// File: main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "tasks.txt"
#define TEMP_FILENAME "temp_tasks.txt"
#define MAX_LINE_LENGTH 256

// Function Prototypes
void show_usage();
void list_tasks();
void add_task(const char *task);
void remove_task(int task_number);

/**
 * @brief Main function to parse command-line arguments and call appropriate functions.
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_usage();
        return 1;
    }

    if (strcmp(argv[1], "list") == 0) {
        list_tasks();
    } else if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf("Error: Missing task description for 'add' command.\n");
            show_usage();
            return 1;
        }
        add_task(argv[2]);
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc < 3) {
            printf("Error: Missing task number for 'remove' command.\n");
            show_usage();
            return 1;
        }
        int task_num = atoi(argv[2]);
        if (task_num <= 0) {
            printf("Error: Invalid task number. Please provide a positive integer.\n");
            return 1;
        }
        remove_task(task_num);
    } else {
        printf("Error: Unknown command '%s'\n", argv[1]);
        show_usage();
        return 1;
    }

    return 0;
}

/**
 * @brief Prints the usage instructions for the program.
 */
void show_usage() {
    printf("\n--- Simple C To-Do List Manager ---\n");
    printf("Usage: todo <command> [arguments]\n\n");
    printf("Commands:\n");
    printf("  list              Show all current tasks.\n");
    printf("  add \"<task>\"      Add a new task to the list.\n");
    printf("  remove <number>   Remove a task by its number.\n\n");
}

/**
 * @brief Lists all tasks from the tasks.txt file.
 */
void list_tasks() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No tasks found. Your to-do list is empty!\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int task_count = 1;

    printf("\n--- Your To-Do List ---\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d. %s", task_count, line);
        task_count++;
    }

    if (task_count == 1) {
        printf("Your to-do list is empty!\n");
    }
    printf("-----------------------\n");

    fclose(file);
}

/**
 * @brief Adds a new task to the end of the tasks.txt file.
 * @param task The description of the task to add.
 */
void add_task(const char *task) {
    FILE *file = fopen(FILENAME, "a"); // "a" for append mode
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(file, "%s\n", task);
    fclose(file);

    printf("Successfully added task: \"%s\"\n", task);
}

/**
 * @brief Removes a task by its line number.
 * This works by writing all other tasks to a temporary file,
 * then replacing the original file with the temporary one.
 * @param task_number The 1-based index of the task to remove.
 */
void remove_task(int task_number) {
    FILE *original_file = fopen(FILENAME, "r");
    if (original_file == NULL) {
        printf("Error: No tasks to remove.\n");
        return;
    }

    FILE *temp_file = fopen(TEMP_FILENAME, "w");
    if (temp_file == NULL) {
        perror("Error creating temporary file");
        fclose(original_file);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int current_line = 1;
    int task_found = 0;

    while (fgets(line, sizeof(line), original_file) != NULL) {
        if (current_line != task_number) {
            fputs(line, temp_file);
        } else {
            task_found = 1;
        }
        current_line++;
    }

    fclose(original_file);
    fclose(temp_file);

    if (!task_found) {
        printf("Error: Task %d not found.\n", task_number);
        remove(TEMP_FILENAME); // Clean up the temporary file
    } else {
        // Replace the original file with the updated temporary file
        if (remove(FILENAME) != 0) {
            perror("Error deleting original file");
            exit(1);
        }
        if (rename(TEMP_FILENAME, FILENAME) != 0) {
            perror("Error renaming temporary file");
            exit(1);
        }
        printf("Successfully removed task #%d.\n", task_number);
    }
}

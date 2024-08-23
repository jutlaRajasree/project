import sys

class ToDoList:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append({"task": task, "completed": False})
        print("Task added successfully!")

    def remove_task(self, index):
        try:
            del self.tasks[index]
            print("Task removed successfully!")
        except IndexError:
            print("Task index out of range!")

    def mark_completed(self, index):
        try:
            self.tasks[index]["completed"] = True
            print("Task marked as completed!")
        except IndexError:
            print("Task index out of range!")

    def display_tasks(self):
        if not self.tasks:
            print("No tasks.")
        else:
            for i, task in enumerate(self.tasks):
                status = "Completed" if task["completed"] else "Pending"
                print(f"{i + 1}. {task['task']} - {status}")

def main():
    todo_list = ToDoList()

    while True:
        print("\n1. Add Task\n2. Remove Task\n3. Mark Task as Completed\n4. Display Tasks\n5. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            task = input("Enter task: ")
            todo_list.add_task(task)
        elif choice == '2':
            index = int(input("Enter index of task to remove: ")) - 1
            todo_list.remove_task(index)
        elif choice == '3':
            index = int(input("Enter index of task to mark as completed: ")) - 1
            todo_list.mark_completed(index)
        elif choice == '4':
            todo_list.display_tasks()
        elif choice == '5':
            print("Exiting program...")
            sys.exit()
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()

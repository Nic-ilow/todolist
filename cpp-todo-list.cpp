// cpp-todo-list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
#include <ctime>


class ToDoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    ToDoItem() : id(0), description(""), completed(false) {}
    ~ToDoItem() = default;

    bool create(std::string new_description, std::list<int> inuse_ids) {
        // generates a random integer between 1 and 100
        if (inuse_ids.size() == 0) {
            id = 1;
        }

        else {
            id = inuse_ids.back() + 1;
        }
        description = new_description;
        inuse_ids.push_back(id);
        return true;
    }

    void setCompleted(bool val) { 
        completed = val;
    }

    void editDescription(std::string new_description) {
        description = new_description;
    }

    void updateId(int new_id) {
        id = new_id;
    }

    int getId() {
        return id;
    }

    std::string getDescription() {
        return description;
    }

    int isCompleted() {
        return completed;
    }
};

int main()
{
    char input_option;
    int input_id;
    int new_id;
    std::string user_description;
    std::list<int> inuse_ids;

    std::string version = "v0.1.0";
    std::list<ToDoItem> todoItems;
    std::list<ToDoItem>::iterator it;

    todoItems.clear();

    while (1) {
        system("cls");
        std::cout << "Todo List - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->isCompleted() ? "Done" : "Not Done";
            std::cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << std::endl;
        }
        if (todoItems.empty()) {
            std::cout << "add your first item!" << std::endl;
        }

        std::cout << "[a]dd a new todo" << std::endl;
        std::cout << "[c]omplete a todo" << std::endl;
        std::cout << "[r]emove a task" << std::endl;
        std::cout << "[e]dit description" << std::endl;
        std::cout << "[q]uit" << std::endl;


        std::cout << "Make your choice, use the inputs in brackets: ";
        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "I hope you enjoyed your experience :)" << std::endl;
            break;
        }

        else if (input_option == 'a') {
            std::cout << "Please enter a description for your task: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, user_description);
            
            ToDoItem item;
            item.create(user_description, inuse_ids);
            todoItems.push_back(item);
            inuse_ids.push_back(item.getId());
        }

        else if (input_option == 'r') {
            std::cout << "Enter the id of the to-do list item to remove: ";
            std::cin.clear();
            std::cin >> input_id;

            if (todoItems.size() == 1) {
                todoItems.clear();
                inuse_ids.clear();
            }

            else {
                new_id = 1;
                for (it = todoItems.begin(); it != todoItems.end(); it++) {

                    if (input_id == it->getId()) {
                        it = todoItems.erase(it);
                        inuse_ids.remove(new_id);
                    }

                    it->updateId(new_id);
                    new_id++;
                }
            }
        }

        else if (input_option == 'e') {
            std::cout << "Enter the id of the to-do list item you want to update: ";
            std::cin.clear();
            std::cin >> input_id;

            std::cout << "Now enter your new_description for this item: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, user_description);

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->editDescription(user_description);
                    break;
                }
            }
        }

        else if (input_option == 'c') {
            std::cout << "Enter id of task to mark as completed: " << std::endl;
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
        else {
            std::cout << input_option << " is an invalid input. Try one of the square bracketed inputs" << std::endl;
        }

    }


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

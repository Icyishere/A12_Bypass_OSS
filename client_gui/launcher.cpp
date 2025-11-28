#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_CMD "cls"
    #define PYTHON_CMD "python"
#else
    #include <unistd.h>
    #define CLEAR_CMD "clear"
    #define PYTHON_CMD "python3"
#endif

void clear_screen() {
    std::system(CLEAR_CMD);
}

void print_header() {
    std::cout << "\033[1;35m" << "iOS Activation Tool - C++ Launcher" << "\033[0m" << std::endl;
    std::cout << "\033[1;36m" << "==================================" << "\033[0m" << std::endl;
}

void run_activator() {
    clear_screen();
    print_header();
    std::cout << "\nStarting Activator (Python)...\n" << std::endl;

    std::string cmd = std::string(PYTHON_CMD) + " client/activator.py";
    int result = std::system(cmd.c_str());

    if (result != 0) {
        std::cerr << "\n\033[1;31mError: Activator script exited with code " << result << "\033[0m" << std::endl;
    }

    std::cout << "\nPress Enter to return to menu...";
    std::cin.ignore();
    std::cin.get();
}

void show_help() {
    clear_screen();
    print_header();
    std::cout << "\n\033[1;33mHelp / Instructions:\033[0m\n" << std::endl;
    std::cout << "1. Make sure your device is connected via USB." << std::endl;
    std::cout << "2. Ensure the server is running." << std::endl;
    std::cout << "3. Select 'Run Activator' to start the process." << std::endl;
    std::cout << "4. Follow the on-screen instructions in the Python script." << std::endl;

    std::cout << "\nPress Enter to return to menu...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    while (true) {
        clear_screen();
        print_header();

        std::cout << "\n\033[1;32mMenu:\033[0m" << std::endl;
        std::cout << "1. Run Activator" << std::endl;
        std::cout << "2. Help" << std::endl;
        std::cout << "3. Exit" << std::endl;

        std::cout << "\n\033[1;34mSelect option: \033[0m";

        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            run_activator();
        } else if (choice == "2") {
            show_help();
        } else if (choice == "3") {
            std::cout << "Exiting..." << std::endl;
            break;
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    return 0;
}

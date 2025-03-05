# Name Matching Game - "SELF"

This is a simple C++ program that takes two names as input and removes common letters between them. The remaining characters are counted and used to determine a relationship status based on the acronym **SELF**:

- **S** - Single
- **E** - Enemies
- **L** - Lovers
- **F** - Friends

## Features
- Takes two names as input from the user
- Cancels out common letters between them
- Counts remaining characters
- Uses the count to determine the relationship status
- Case-insensitive input handling

## How It Works
1. The user enters two names.
2. The program converts both names to lowercase to ensure case-insensitivity.
3. It removes common characters from both names.
4. The count of remaining characters is used to iterate through "SELF", eliminating letters one by one until one remains.
5. The final letter determines the relationship status.

## Example Usage
### Input:
```
Enter the first name: Abdullah
Enter the second name: Ahmad
```

### Output:
```
🌟 Welcome to the Love Calculator! 🌟
--------------------------------------
Enter first name: abdullah
Enter second name: ahmad
Common alphabets: a d a h 
--------------------------------------
Remaining count: 5
Your relationship status is: Friends
--------------------------------------
```

## Installation & Running the Program
1. Clone the repository:
   ```sh
   git clone https://github.com/Abdullah-319/self_calculator-in-cpp.git
   ```
2. Navigate to the project folder:
   ```sh
   cd self_calculator-in-cpp
   ```
3. Compile the program:
   ```sh
   g++ self.cpp -o self.exe 
   ```
4. Run the executable:
   ```sh
   self.exe
   ```

## Requirements
- A C++ compiler (e.g., g++, Clang, MSVC)
- Any operating system (Windows, macOS, Linux)

---

Happy coding! 🚀💜


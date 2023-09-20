# Simple Shell

This is a basic Unix shell implemented in C, designed for simple command execution. It follows strict criteria outlined below:

## Features

- **Command Execution:** The shell accepts one-word commands with optional arguments.

- **Prompt Display:** A prompt is displayed, waiting for the user to enter a command. After execution, the prompt is displayed again.

- **Error Handling:** If an executable cannot be found, an error message is displayed, and the prompt reappears.

- **End of File Handling:** The shell gracefully handles the "end of file" condition (Ctrl+D).

- **Built-in Commands:**
  - `exit`: Allows you to exit the shell.
  - `env`: Displays the current environment.

## Getting Started

  1. **Clone the Repository:**

       ```bash
       git clone https://github.com/yourusername/simple-unix-shell.git
	```

  2. **Compile the Code:**

   ```bash
   cd simple-unix-shell
   gcc shell.c -o shell
   ```

 3. **Run the Shell:**

    ```bash
     ./shell
        ```

## Contributors
  - [Mohamed Amr](https://github.com/MohamedAmrF)	  
  - [Mariem Ehab](https://github.com/MaryEhb)

## License

  This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

  - This project was created to demonstrate a minimalistic Unix shell in C.
  - No advanced features like semicolons, pipes, or redirections are supported, keeping the implementation simple and straightforward.

  ```

				

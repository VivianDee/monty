# Monty Bytecode Interpreter

The Monty Bytecode Interpreter is a program written in C that executes Monty byte code files. It provides a stack-based interpreter that supports various operations on a stack data structure.

## Usage

To run the Monty program, use the following command:

```
./monty file
```

Where `file` is the path to the file containing Monty byte code.

## Features

The Monty program supports the following features:

- **push**: Pushes an element onto the stack.
- **pall**: Prints all elements of the stack.
- **malloc and free**: Utilizes dynamic memory allocation and deallocation.

## Error Handling

The Monty program includes error handling for various scenarios:

- If the user does not provide any file or provides more than one argument, an error message is displayed: `USAGE: monty file`.
- If it's not possible to open the file, an error message is displayed: `Error: Can't open file <file>`.
- If the file contains an invalid instruction, an error message is displayed: `L<line_number>: unknown instruction <opcode>`.
- If `malloc` fails to allocate memory, an error message is displayed: `Error: malloc failed`.

## Bytecode File Format

Monty byte code files have a specific format:

```
opcode [argument]
```

- Each line contains an opcode followed by an optional argument.
- Opcodes and arguments are space-separated.
- Empty lines and lines starting with `#` are ignored.

## Example Monty Bytecode File

Here's an example of a Monty byte code file that demonstrates the usage of push and pall operations:

```
push 1
push 2
push 3
pall
```

Output:
```
3
2
1
```

## Contributing

Contributions to the Monty Bytecode Interpreter are welcome! If you encounter any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). See the [LICENSE](LICENSE) file for more details.

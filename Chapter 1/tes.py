def detab(input_string, tab_width):
    output_string = ""
    column = 1

    for char in input_string:
        if char == '\t':
            spaces_needed = tab_width - (column - 1) % tab_width
            output_string += ' ' * spaces_needed
            column += spaces_needed
        else:
            output_string += char
            column += 1
            if char == '\n':
                column = 1  # Reset column count for new line

    return output_string

# Example usage:
input_text = "Hello\tworld!\n\tThis\tis\ta\ttest."
tab_width = 2
result = detab(input_text, tab_width)
print(input_text)
print(result)


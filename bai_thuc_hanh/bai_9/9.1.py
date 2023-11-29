# Hàm đọc dữ liệu từ file
def read_numbers_from_file(filename):
    numbers = []
    with open(filename, 'r') as file:
        for line in file:
            number = int(line.strip())
            numbers.append(number)
    return numbers

# Hàm ghi kết quả vào file
def write_result_to_file(filename, result):
    with open(filename, 'w') as file:
        file.write(str(result))

# Hàm thực hiện phép toán (+, -, *, /) với số lớn
def perform_operation(numbers, operator):
    result = numbers[0]
    for number in numbers[1:]:
        if operator == '+':
            result += number
        elif operator == '-':
            result -= number
        elif operator == '*':
            result *= number
        elif operator == '/':
            result /= number
    return result

# Tên file đầu vào+
input_file = 'input.txt'
# Tên file đầu ra
output_file = 'output.txt'

# Đọc các số từ file đầu vào
numbers = read_numbers_from_file(input_file)

# Thực hiện phép toán (+, -, *, /) với các số đã đọc
# Ở đây, ta giả sử phép toán là cộng (+)
operator = '+'
result = perform_operation(numbers, operator)

# Ghi kết quả vào file đầu ra
write_result_to_file(output_file, result)

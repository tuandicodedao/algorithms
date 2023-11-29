from PIL import Image

# Hàm hiển thị hình ảnh lên màn hình
def display_image(image):
    image.show()

# Hàm lưu hình ảnh vào file
def save_image_to_file(image, filename):
    image.save(filename)

# Hàm đối xứng trục của hình ảnh
def flip_axis(image):
    flipped_image = image.transpose(Image.FLIP_LEFT_RIGHT)
    return flipped_image

# Hàm đối xứng điểm của hình ảnh
def flip_point(image):
    flipped_image = image.transpose(Image.FLIP_TOP_BOTTOM)
    return flipped_image

# Hàm quay hình ảnh
def rotate_image(image, angle):
    rotated_image = image.rotate(angle)
    return rotated_image

# Hàm phóng to thu nhỏ hình ảnh
def resize_image(image, scale):
    width, height = image.size
    new_width = int(width * scale)
    new_height = int(height * scale)
    resized_image = image.resize((new_width, new_height))
    return resized_image

# Tên file hình ảnh đầu vào
input_image_file = 'input_image.jpg'

# Đọc hình ảnh từ file
input_image = Image.open(input_image_file)

while True:
    # Hiển thị menu
    print("1. Hiển thị hình ảnh")
    print("2. Lưu hình ảnh")
    print("3. Đối xứng trục")
    print("4. Đối xứng điểm")
    print("5. Quay hình ảnh")
    print("6. Phóng to/Thu nhỏ")
    print("0. Thoát")

    # Lựa chọn của người dùng
    choice = input("Nhập lựa chọn của bạn: ")

    if choice == '1':
        # Hiển thị hình ảnh
        display_image(input_image)
    elif choice == '2':
        # Lưu hình ảnh vào file
        output_image_file = input("Nhập tên file để lưu hình ảnh: ")
        save_image_to_file(input_image, output_image_file)
        print(f"Đã lưu hình ảnh vào file: {output_image_file}")
    elif choice == '3':
        # Đối xứng trục
        flipped_axis_image = flip_axis(input_image)
        display_image(flipped_axis_image)
    elif choice == '4':
        # Đối xứng điểm
        flipped_point_image = flip_point(input_image)
        display_image(flipped_point_image)
    elif choice == '5':
        # Quay hình ảnh
        angle = float(input("Nhập góc quay (đơn vị: độ): "))
        rotated_image = rotate_image(input_image, angle)
        display_image(rotated_image)
    elif choice == '6':
        # Phóng to/Thu nhỏ
        scale = float(input("Nhập tỷ lệ phóng to/thu nhỏ: "))
        resized_image = resize_image(input_image, scale)
        display_image(resized_image)
    elif choice == '0':
        # Thoát chương trình
        break
    else:
        print("Lựa chọn không hợp lệ. Vui lòng thử lại.")

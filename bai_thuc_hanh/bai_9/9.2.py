import cv2

# Hàm ghi dữ liệu ảnh vào file
def save_image_to_file(image, filename):
    cv2.imwrite(filename, image)

# Hàm ghi dữ liệu văn bản vào file
def save_text_to_file(text, filename):
    with open(filename, 'w') as file:
        file.write(text)

# Sử dụng webcam để đọc dữ liệu
def read_from_webcam(save_as_image=False, image_filename=None, save_as_text=False, text_filename=None):
    # Khởi tạo webcam
    webcam = cv2.VideoCapture(0)

    # Đọc từng khung hình từ webcam
    ret, frame = webcam.read()

    # Kiểm tra và lưu dữ liệu ảnh
    if save_as_image and image_filename:
        save_image_to_file(frame, image_filename)
        print(f"Đã lưu ảnh vào file: {image_filename}")

    # Kiểm tra và lưu dữ liệu văn bản
    if save_as_text and text_filename:
        # Xử lý dữ liệu văn bản (ở đây ta lấy giá trị pixel đầu tiên)
        pixel_value = frame[0, 0]
        text_data = f"Giá trị pixel đầu tiên: {pixel_value}"
        save_text_to_file(text_data, text_filename)
        print(f"Đã lưu văn bản vào file: {text_filename}")

    # Giải phóng webcam
    webcam.release()

# Gọi hàm để đọc từ webcam và lưu dữ liệu
read_from_webcam(save_as_image=True, image_filename="captured_image.jpg", save_as_text=True, text_filename="captured_text.txt")

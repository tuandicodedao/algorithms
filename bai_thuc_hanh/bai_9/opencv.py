import numpy as np

def gradient_descent(X, y, learning_rate=0.01, num_iterations=1000):
    # Khởi tạo các tham số ban đầu
    theta = np.zeros(X.shape[1])  # Khởi tạo theta bằng 0
    m = len(y)  # Số lượng mẫu

    # Gradient Descent
    for iteration in range(num_iterations):
        # Tính giá trị dự đoán
        y_pred = np.dot(X, theta)

        # Tính độ lỗi và gradient
        error = y_pred - y
        gradient = 1/m * np.dot(X.T, error)

        # Cập nhật theta
        theta -= learning_rate * gradient

    return theta

# Dữ liệu mẫu
X = np.array([[1, 1], [1, 2], [1, 3], [1, 4]])  # Biến độc lập (bao gồm cột 1 cho theta0)
y = np.array([2, 4, 6, 8])  # Biến phụ thuộc

# Thêm cột 1 vào X cho theta0
X = np.concatenate((np.ones((X.shape[0], 1)), X), axis=1)

# Áp dụng Gradient Descent
theta = gradient_descent(X, y)

# In kết quả
print("Hệ số tìm được:")
print("theta0 =", theta[0])
print("theta1 =", theta[1])
print("theta2 =", theta[2])

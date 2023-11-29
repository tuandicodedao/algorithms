#include <stdio.h>

void maxPositiveSubarray(int arr[], int n) {
    int maxSum = 0;       //Tong lon nhat cua day con toan duong
    int currentSum = 0;   // Tong hien tai cua day con toan duong
    int start = -1;       // chi so bat dau cua day con toan duong
    int end = -1;         //chi so ket thuc cua day con toan duong

    int tempStart = -1;   // chi so bat dau cua day con toan duong tam thoi
    int tempEnd = -1;     // chi so ket thuc cua day con toan duong tam thoi


    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (currentSum <= 0) {
                // Bat dau 1 day moi
                tempStart = i;
                currentSum = arr[i];
            } else {
                // Tiep tuc day con hien tai
                currentSum += arr[i];
            }

            if (currentSum > maxSum) {
                // cap nhat tong lon nhat va chi so ket thuc cua day con
                maxSum = currentSum;
                tempEnd = i;
                start = tempStart;
                end = tempEnd;
            }
        } else {
            // Dat lai tong hien tai ve 0 khi gap so am
            currentSum = 0;
        }
    }

    if (start != -1 && end != -1) {
        // In day con toan duong
        printf("Day con toan duong lon nhat: ");
        for (i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Tong: %d\n", maxSum);
    } else {
        printf("Khong ton tai day toan duong trong mang.\n");
    }
}

int main() {
    int arr[] = {1, -2, 3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    maxPositiveSubarray(arr, n);

    return 0;
}



import cv2

image = cv2.imread('C:\img1.jpg')

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cv2.imshow('Grayscale', gray_image)

for i in range(0,len(gray_image)):
    for j in range(0,len(gray_image[i])):
        gray_image[i][j] = 255 - gray_image[i][j]
        

cv2.imshow('Complement', gray_image)
cv2.waitKey(0) 

cv2.destroyAllWindows()

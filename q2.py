
import numpy as np
import cv2
from skimage.util import random_noise

image = cv2.imread('C:\img1.jpg')
#cv2.imshow('Original', image)
#cv2.waitKey(0)

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cv2.imshow('Grayscale', gray_image)
cv2.waitKey(0)
noise_img = random_noise(gray_image, mode='s&p')

cv2.imshow("Noise",noise_img)


gaus_blur = cv2.GaussianBlur(noise_img,(5,5),0)
avg_blur = cv2.blur(noise_img,(5,5))
noise_img = np.array(255*noise_img, dtype = 'uint8')
med_blur = cv2.medianBlur(noise_img,5)


cv2.imshow("gaus_blur", gaus_blur)
cv2.imshow("md_blur", med_blur)
cv2.imshow("avg_blur", avg_blur)
cv2.waitKey(0)

cv2.destroyAllWindows()


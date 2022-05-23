# -*- coding: utf-8 -*-
"""
Created on Fri May  6 14:53:41 2022

@author: 19pt25
"""

import cv2

image = cv2.imread('C:\img1.jpg')
#cv2.imshow('Original', image)
#cv2.waitKey(0)

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cv2.imshow('Grayscale', gray_image)
#cv2.waitKey(0) 

for i in range(0,len(gray_image)):
    for j in range(0,len(gray_image[i])):
        if(gray_image[i][j] > 128):
            gray_image[i][j] = 255
        else:
            gray_image[i][j] = 0

cv2.imshow('Binary', gray_image)
cv2.waitKey(0) 

cv2.destroyAllWindows()




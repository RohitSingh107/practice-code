
import os
# import random
import numpy as np
import matplotlib.pyplot as plt
import cv2

# Function to generate a random number
def generate_random_number(seed=None):
    if seed is not None:
        random.seed(seed)
    return random.randint(0, 100)

# Function to check imbalance in dataset
def check_imbalance(dataset_path):
    classes = os.listdir(dataset_path)
    num_images_per_class = {cls: len(os.listdir(os.path.join(dataset_path, cls))) for cls in classes}
    class_labels = list(num_images_per_class.keys())
    num_images = list(num_images_per_class.values())

    plt.bar(class_labels, num_images)
    plt.xlabel('Classes')
    plt.ylabel('Number of Images')
    plt.title('Number of Images per Class')
    plt.xticks(rotation=45)
    plt.show()

    min_images = min(num_images)
    max_images = max(num_images)
    if max_images > 2 * min_images:
        imbalanced_class = class_labels[num_images.index(max_images)]
        print(f"The dataset is imbalanced. The imbalanced class is {imbalanced_class}.")
        print("To balance the dataset, methods like data augmentation, oversampling, or undersampling can be used.")
    else:
        print("The dataset is balanced.")

# Function to convert images to grayscale and plot histograms
def plot_histograms(dataset_path, num_samples=8):
    classes = os.listdir(dataset_path)
    sampled_images = random.sample([os.path.join(root, file) for root, _, files in os.walk(dataset_path) for file in files], num_samples)

    for image_path in sampled_images:
        image = cv2.imread(image_path)
        if len(image.shape) > 2:
            gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        else:
            gray_image = image
        plt.figure(figsize=(10, 5))

        plt.subplot(1, 2, 1)
        plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
        plt.title('Original Image')

        plt.subplot(1, 2, 2)
        plt.hist(gray_image.ravel(), 256, [0, 256])
        plt.title('Histogram')

        plt.show()

# Function to perform transformations on images and plot before and after images
def plot_image_transformations(dataset_path, num_samples=1):
    classes = os.listdir(dataset_path)
    sampled_images = random.sample([os.path.join(root, file) for root, _, files in os.walk(dataset_path) for file in files], num_samples)

    for image_path in sampled_images:
        image = cv2.imread(image_path)
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        # Random Rotation
        angle = generate_random_number()
        rotated_image = cv2.rotate(image, cv2.ROTATE_90_CLOCKWISE)

        # Random Cropping
        h, w, _ = image.shape
        crop_top = generate_random_number() % (h // 2)
        crop_bottom = h - (generate_random_number() % (h // 2))
        crop_left = generate_random_number() % (w // 2)
        crop_right = w - (generate_random_number() % (w // 2))
        cropped_image = image[crop_top:crop_bottom, crop_left:crop_right]

        # Random Scale
        scale_factor = generate_random_number() / 100.0
        new_h = int(h * scale_factor)
        new_w = int(w * scale_factor)
        scaled_image = cv2.resize(image, (new_w, new_h))

        plt.figure(figsize=(10, 5))

        plt.subplot(2, 2, 1)
        plt.imshow(image)
        plt.title('Original Image')

        plt.subplot(2, 2, 2)
        plt.imshow(rotated_image)
        plt.title('Rotated Image')

        plt.subplot(2, 2, 3)
        plt.imshow(cropped_image)
        plt.title('Cropped Image')

        plt.subplot(2, 2, 4)
        plt.imshow(scaled_image)
        plt.title('Scaled Image')

        plt.show()

# Example usage:
dataset_path = 'imgdata/'
check_imbalance(dataset_path)
plot_histograms(dataset_path)
plot_image_transformations(dataset_path)

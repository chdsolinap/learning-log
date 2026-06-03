import pytesseract as tess
from PIL import Image
from pathlib import Path

# Tell pytesseract where Tesseract OCR is installed
tess.pytesseract.tesseract_cmd = r"C:\Program Files\Tesseract-OCR\tesseract.exe"

# Get the folder where this Python file is located
BASE_DIR = Path(__file__).parent

# Open the image from the same folder as OCR.py
img = Image.open(BASE_DIR / "ocr-example.png")

# Extract text from the image
text = tess.image_to_string(img)

print(text)
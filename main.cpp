#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

char pixelToASCII(int grayScale) {

    string asciiChars = " .:-=+*#%@";

    grayScale = max(0, min(grayScale, 255));
    int scale = 255 / (asciiChars.length() - 1);
    int index = grayScale / scale;

    index = max(0, min(index, static_cast<int>(asciiChars.length()) - 1));
    return asciiChars[index];
}


int main() {
    Image i;
    if (i.loadFromFile("img.jpg")) {
        cout << "Image loaded successfully." << endl;
    } else {
        cerr << "Error: couldn't load image." << endl;
        return -1;
    }

    Vector2u imageSize = i.getSize();
    int xSize = imageSize.x;
    int ySize = imageSize.y;

    if (xSize == 0 || ySize == 0) {
        cerr << "Error: image is empty." << endl;
        return -1;
    }

    Color tempColor;
    int grayScale = 0;

    for (int y = 0; y < ySize; y += 2) {
        for (int x = 0; x < xSize; x++) {
            tempColor = i.getPixel(x, y);
            grayScale = static_cast<int>(tempColor.r * 0.2126 + tempColor.g * 0.7152 + tempColor.b * 0.0722);
            cout << pixelToASCII(grayScale);
            cout << pixelToASCII(grayScale);
        }
        cout << endl;
    }

    return 0;
}

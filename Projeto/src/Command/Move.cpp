//
// Created by guilherme-nunes on 5/20/25.
//
#include "Command/Move.hpp"
#include "Image.hpp"
#include <sstream>
namespace prog {
    namespace command {

        Move::Move(int x, int y): Command("Move"), x(x), y(y) {}

        Move::~Move() {}

        Image* Move::apply(Image* img) {
            if (img == nullptr) return nullptr;

            int width = img->width();
            int height = img->height();

            // Create new image with same dimensions, filled with background color (top-left pixel)
            Image* new_img = new Image(width, height, img->at(0, 0));

            // Process each pixel from the original image
            for (int col = 0; col < height; ++col) {
                for (int row = 0; row < width; ++row) {
                    // Calculate new position after movement
                    int new_x = (row + x );
                    int new_y = (col + y);

                    // Only copy pixel if it stays within image boundaries
                    // Pixels moved outside are lost (unlike slide which w
                    if(new_x < width && new_y < height){
                        new_img->at(new_x,new_y) = img->at(row,col);
                    }
                }
            }

            delete img;
            return new_img;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y;
            return ss.str();
        }

    }
}
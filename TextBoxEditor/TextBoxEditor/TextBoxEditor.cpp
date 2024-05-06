#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <string>

std::string concatenateChars();
void deleteChars(int);
void inputText(char c, int posleft);
std::vector<char> Text;
int main() {
    unsigned int xpos = 0;
    std::string Printable;
    sf::RenderWindow window(sf::VideoMode(500, 70), "Mini editor de texto");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text(Printable, font, 50);
    text.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            system("cls");
            if (event.type == sf::Event::Closed) {
                window.close();
                break; 
            }

            if (event.type == sf::Event::KeyPressed) {
                // Get the key that was pressed
                sf::Keyboard::Key key = event.key.code;

                // Check for special keys (printable characters are handled below)
                if (key == sf::Keyboard::Escape) {
                    window.close();
                    break;
                }
                else if (key == sf::Keyboard::Return) {
                }
                else if (key == sf::Keyboard::Tab) {
                }
                // ... add checks for other special keys as needed

                // Check for printable characters
                else if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z) {
                    char pressedChar = key - sf::Keyboard::A + 'a';
                    inputText(pressedChar,xpos);
                    if(xpos<Text.size())
                    xpos++;
                    std::cout << xpos << std::endl;
                }
                else if (key >= sf::Keyboard::Num0 && key <= sf::Keyboard::Num9) {
                    char pressedChar = key - sf::Keyboard::Num0 + '0';
                    inputText(pressedChar, xpos);
                    if (xpos < Text.size())
                       std::cout << xpos << std::endl;
                    xpos++;
                }
                else if (key == sf::Keyboard::Space) {
                    inputText(' ', xpos);
                    if (xpos < Text.size())
                    xpos++;
                    std::cout << xpos << std::endl;
                }
                else if (key == sf::Keyboard::BackSpace) {
                    deleteChars(xpos);
                    if (xpos > 0) {
                        xpos--;
                        std::cout << xpos << std::endl;

                    }
                }
                else if (key == sf::Keyboard::Left) {
                    if (xpos > 0) {
                        xpos--;
                        std::cout << xpos << std::endl;

                    }
                }
                else if (key == sf::Keyboard::Right) {
                    if (xpos < Text.size())
                    xpos++;
                    std::cout << xpos << std::endl;
                }
            }
            std::cout << "Posicion del cursor: " << xpos << std::endl;
            Printable = concatenateChars();
            text.setString(Printable);

        }

        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
    }

    return 0;
}

void inputText(char c, int posleft) {
    if (Text.empty()) {
        Text.push_back(c);
    }
    else if (posleft <= 0) {
        Text.insert(Text.begin(), c);
    }
    else if (posleft < Text.size()) {
        Text.insert(Text.begin() + posleft, c);
    }
    else {
        Text.push_back(c);
    }

}

std::string concatenateChars() {
    std::string string;
    if (!Text.empty()) {
        for (int i = 0; i < Text.size(); i++) {
            string = string + Text[i];
        }
        return string;
    }
    
    return "";
}

void deleteChars(int posleft) {
    if (Text.empty()) {
        return;
    }
    if (Text.size() == 1 && posleft == 1) {
        Text.erase(Text.begin() + posleft-1);
    }
    if (Text.size() > 1&&posleft<=Text.size()&&posleft>0) {
        Text.erase(Text.begin() + posleft - 1);
    }

}


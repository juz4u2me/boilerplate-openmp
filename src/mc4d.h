#include <vector>

class MC4D {
    private:
        std::vector<int> draw;

    public:
        MC4D();
        void generateDraw();
        double match(int guess, int bet);
        double run(int guess, int bet);
        void display();
};
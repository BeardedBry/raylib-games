// #include <cstdio>
#include "raylib.h"

int main()
{
    // window dimensions
    int width = 800;
    int height = 450;
    InitWindow(width, height, "Axe Game");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length = 50;
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    int circleSpeed = 10;

    bool collision_with_axe = 
                    (r_circle_x >= l_axe_x) && 
                    (l_circle_x <= r_axe_x) && 
                    (u_circle_y >= b_axe_y) && 
                    (b_circle_y >= u_axe_y);


    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", width / 2, height / 2, 20, RED);
        }
        else
        {
            // Game logic begins

            // update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision
            collision_with_axe = 
                    (r_circle_x >= l_axe_x) && 
                    (l_circle_x <= r_axe_x) && 
                    (u_circle_y <= b_axe_y) && 
                    (b_circle_y >= u_axe_y);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // move the axe
            if (axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            axe_y += direction;

            if (IsKeyDown(KEY_D) && (circle_x + circle_radius) <= width)
            {
                circle_x += circleSpeed;
            }
            if (IsKeyDown(KEY_A) && (circle_x - circle_radius) >= 0)
            {
                circle_x -= circleSpeed;
            }
            if (IsKeyDown(KEY_W) && (circle_y - circle_radius) >= 0)
            {
                circle_y -= circleSpeed;
            }
            if (IsKeyDown(KEY_S) && (circle_y + circle_radius) <= height)
            {
                circle_y += circleSpeed;
            }
        }

        // Game logic ends

        EndDrawing();
    }
}
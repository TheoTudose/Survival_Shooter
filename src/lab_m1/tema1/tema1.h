#pragma once

#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "obstacle.h"
#include "components/simple_scene.h"


namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        struct ViewportSpace
        {
            ViewportSpace() : x(0), y(0), width(1), height(1) {}
            ViewportSpace(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        struct LogicSpace
        {
            LogicSpace() : x(0), y(0), width(1), height(1) {}
            LogicSpace(float x, float y, float width, float height)
                : x(x), y(y), width(width), height(height) {}
            float x;
            float y;
            float width;
            float height;
        };

        struct PlayerPos
        {
            PlayerPos() : x(0), y(0) {}
            PlayerPos(float x, float y)
                : x(x), y(y) {}
            float x;
            float y;
        };

        

    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void DrawScene(glm::mat3 visMatrix);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        glm::mat3 VisualizationTransf2D(const LogicSpace& logicSpace, const ViewportSpace& viewSpace);
        glm::mat3 VisualizationTransf2DUnif(const LogicSpace& logicSpace, const ViewportSpace& viewSpace);

        void SetViewportArea(const ViewportSpace& viewSpace, glm::vec3 colorColor = glm::vec3(0), bool clear = true);

    protected:
        float length;
        ViewportSpace viewSpace;
        ViewportSpace miniMap;
        LogicSpace logicSpace;
        PlayerPos playerPos;
        glm::mat3 modelMatrix, visMatrix;
        float translateX, translateY;
        float angularStep;
        Player* player;
        Obstacle*  obstacles;
        std::vector<Projectile> weapon;
        std::vector<Enemy> enemies;
        float fireRate;
        float wave;
        bool showScore;
        int score;
        std::vector<Projectile>::iterator i;
        std::vector<Enemy>::iterator j;
    };
}   // namespace m1


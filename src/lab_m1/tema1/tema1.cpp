#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"
#include "player.h"
#include "enemy.h"
#include "projectile.h"
#include "obstacle.h"
#include "collisions.h"



using namespace std;
using namespace m1;



Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}



void Tema1::Init()
{
    showScore = false;
    score = 0;
    wave = 0;
    player = new Player;
    obstacles = new Obstacle[46];
    auto camera = GetSceneCamera();
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);
    logicSpace.x = 0;
    logicSpace.y = 0;
    logicSpace.width = 30;
    logicSpace.height = 20;
    
    translateX = 0;
    translateY = 0;

    playerPos.x = 0;
    playerPos.y = 0;

    glm::vec3 corner = glm::vec3(0.001, 0.001, 0);
    length = 1;

    angularStep = 0;

    //Pereti exteriori
    obstacles[0].setPos(-7, 10);
    obstacles[0].setSize(20.0f, 1.0f);
    obstacles[1].setPos(17, 10);
    obstacles[1].setSize(28.0f, 1.0f);
    obstacles[2].setPos(-7, 11);
    obstacles[2].setSize(1.0f, 6.0f);
    obstacles[3].setPos(-7, 21);
    obstacles[3].setSize(1.0f, 10.0f);
    obstacles[4].setPos(-7, 31);
    obstacles[4].setSize(5.0f, 1.0f);
    obstacles[5].setPos(2, 31);
    obstacles[5].setSize(7.0f, 1.0f);
    obstacles[6].setPos(13, 31);
    obstacles[6].setSize(15.0f, 1.0f);
    obstacles[7].setPos(32, 31);
    obstacles[7].setSize(3.0f, 1.0f);
    obstacles[8].setPos(39, 31);
    obstacles[8].setSize(6.0f, 1.0f);
    obstacles[9].setPos(44, 11);
    obstacles[9].setSize(1.0f, 2.0f);
    obstacles[10].setPos(44, 17);
    obstacles[10].setSize(1.0f, 14.0f);
    //Pereti interiori
    obstacles[11].setPos(-5, 22);
    obstacles[11].setSize(4.0f, 0.5f);
    obstacles[12].setPos(2, 22);
    obstacles[12].setSize(3.0f, 0.5f);
    obstacles[13].setPos(5, 22);
    obstacles[13].setSize(0.5f, 9.0f);
    obstacles[14].setPos(22, 11);
    obstacles[14].setSize(0.5f, 13.0f);
    obstacles[15].setPos(22, 24);
    obstacles[15].setSize(4.0f, 0.5f);
    obstacles[16].setPos(30, 24);
    obstacles[16].setSize(3.0f, 0.5f);
    obstacles[17].setPos(33, 21);
    obstacles[17].setSize(0.5f, 10.0f);
    obstacles[18].setPos(33.5, 21);
    obstacles[18].setSize(2.0f, 0.5f);
    obstacles[19].setPos(39, 21);
    obstacles[19].setSize(5.0f, 0.5f);
    obstacles[20].setPos(40, 11);
    obstacles[20].setSize(0.5f, 2.0f);
    obstacles[21].setPos(40, 17);
    obstacles[21].setSize(0.5f, 4.0f);
    //Obstacole
    obstacles[22].setPos(9, 17);
    obstacles[22].setSize(8.0f, 4.0f);
    obstacles[23].setPos(-4, 11);
    obstacles[23].setSize(4.0f, 0.4f);
    obstacles[24].setPos(0, 11);
    obstacles[24].setSize(4.0f, 0.6f);
    obstacles[25].setPos(4, 11);
    obstacles[25].setSize(4.0f, 0.8f);
    obstacles[26].setPos(8, 11);
    obstacles[26].setSize(4.0f, 1.0f);
    obstacles[27].setPos(-5, 23);
    obstacles[27].setSize(1.0f, 1.5f);
    obstacles[28].setPos(-5, 27);
    obstacles[28].setSize(1.5f, 1.2f);
    obstacles[29].setPos(3, 27);
    obstacles[29].setSize(1.5f, 1.2f);
    obstacles[30].setPos(22.5f, 11);
    obstacles[30].setSize(2.0f, 6.0f);
    obstacles[31].setPos(24.5f, 11);
    obstacles[31].setSize(6.0f, 2.0f);
    obstacles[32].setPos(30.5f, 11);
    obstacles[32].setSize(6.0f, 1.5f);
    obstacles[33].setPos(41, 11);
    obstacles[33].setSize(2.5f, 0.5f);
    obstacles[34].setPos(41, 20.5f);
    obstacles[34].setSize(2.5f, 0.5f);
    obstacles[35].setPos(40, 30);
    obstacles[35].setSize(1.5f, 1);
    obstacles[36].setPos(41.5f, 29);
    obstacles[36].setSize(2.5f, 2);
    obstacles[37].setPos(43, 27.5f);
    obstacles[37].setSize(1, 1.5f);
    obstacles[38].setPos(-1, 4);
    obstacles[38].setSize(6.0f, 2.5f);
    obstacles[39].setPos(8, 7);
    obstacles[39].setSize(3.0f, 3.0f);
    obstacles[40].setPos(29, 0.0f);
    obstacles[40].setSize(10.0f, 3.0f);
    obstacles[41].setPos(-1, 37.0f);
    obstacles[41].setSize(10.0f, 3.0f);
    obstacles[42].setPos(3.5f, 32);
    obstacles[42].setSize(4.0f, 1.0f);
    obstacles[43].setPos(16, 32);
    obstacles[43].setSize(3.0f, 4.0f);
    obstacles[44].setPos(40, 32);
    obstacles[44].setSize(4.0f, 3.0f);
    obstacles[45].setPos(26, 37.0f);
    obstacles[45].setSize(10.0f, 3.0f);
    

    for (int i = 0; i < 46; i++) 
    {
        obstacles[i].setCenterX();
        obstacles[i].setCenterY();
    }

    Mesh* obstacle = object2D::CreateSquare("obstacle", corner, length, glm::vec3(0, 1, 0), true);
    AddMeshToList(obstacle);

    Mesh* obstacle2 = object2D::CreateSquare("obstacle2", glm::vec3(0.001, 0.001, 0.001), length, glm::vec3(0));
    AddMeshToList(obstacle2);

    Mesh* harta = object2D::CreateSquare("harta", corner, length, glm::vec3(0, 0.502, 0.502), true);
    AddMeshToList(harta);

    Mesh* harta2 = object2D::CreateSquare("harta2", corner, length, glm::vec3(0.5f), true);
    AddMeshToList(harta2);

    Mesh* circle = object2D::CreateCircle("circle1", glm::vec3(0.001, 0.001, 1), player->getRadius(), player->getColor());
    AddMeshToList(circle);

    Mesh* circle2 = object2D::CreateCircle("circle2", glm::vec3(0.001, 0.001, 1), player->getRadius() + 0.1, glm::vec3(0));
    AddMeshToList(circle2);

    Mesh* hBar = object2D::CreateSquare("hBar", glm::vec3(0.001, 0.001, 1), length, glm::vec3(1, 0, 0), true);
    AddMeshToList(hBar);
    Mesh* hBar2 = object2D::CreateSquare("hBar2", glm::vec3(0.001, 0.001, 1), length, glm::vec3(1, 0, 0));
    AddMeshToList(hBar2);

    Mesh* projectile1 = object2D::CreateSquare("projectile", glm::vec3(0.001, 0.001, 0.8), length, glm::vec3(0.000, 0.749, 1.000), true);
    AddMeshToList(projectile1);

    Mesh* enemy1 = object2D::CreateSquare("enemy1", glm::vec3(0.001, 0.001, 0.8), length * 2, glm::vec3(1, 0, 1), true);
    AddMeshToList(enemy1);
   
    Mesh* enemy2 = object2D::CreateCircle("enemy2", glm::vec3(0.001, 0.001, 0.9), (length + 0.1f) / 2.0f, glm::vec3(0));
    AddMeshToList(enemy2);
}


glm::mat3 Tema1::VisualizationTransf2D(const LogicSpace& logicSpace, const ViewportSpace& viewSpace)
{
    float sx, sy, tx, ty;
    sx = viewSpace.width / logicSpace.width;
    sy = viewSpace.height / logicSpace.height;
    tx = viewSpace.x - sx * logicSpace.x;
    ty = viewSpace.y - sy * logicSpace.y;

    return glm::transpose(glm::mat3(
        sx, 0.0f, tx,
        0.0f, sy, ty,
        0.0f, 0.0f, 1.0f));
}


glm::mat3 Tema1::VisualizationTransf2DUnif(const LogicSpace& logicSpace, const ViewportSpace& viewSpace)
{
    float sx, sy, tx, ty, smin;
    sx = viewSpace.width / logicSpace.width;
    sy = viewSpace.height / logicSpace.height;
    if (sx < sy)
        smin = sx;
    else
        smin = sy;
    tx = viewSpace.x - smin * logicSpace.x + (viewSpace.width - smin * logicSpace.width) / 2;
    ty = viewSpace.y - smin * logicSpace.y + (viewSpace.height - smin * logicSpace.height) / 2;

    return glm::transpose(glm::mat3(
        smin, 0.0f, tx,
        0.0f, smin, ty,
        0.0f, 0.0f, 1.0f));
}


void Tema1::SetViewportArea(const ViewportSpace& viewSpace, glm::vec3 colorColor, bool clear)
{
    glViewport(viewSpace.x, viewSpace.y, viewSpace.width, viewSpace.height);

    glEnable(GL_SCISSOR_TEST);
    glScissor(viewSpace.x, viewSpace.y, viewSpace.width, viewSpace.height);

    glClearColor(colorColor.r, colorColor.g, colorColor.b, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);

    GetSceneCamera()->SetOrthographic((float)viewSpace.x, (float)(viewSpace.x + viewSpace.width), (float)viewSpace.y, (float)(viewSpace.y + viewSpace.height), 0.1f, 400);
    GetSceneCamera()->Update();
}


void Tema1::FrameStart()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Tema1::Update(float deltaTimeSeconds)
{
    if (player->getHealth() < 1)
    {
        cout << "Final score is: " << score << "\n";
        exit(1);
    }

    if (showScore)
    {
        cout << "Score: " << score << "\n";
        showScore = false;
    }
    playerPos.x = 15.0f + logicSpace.x;
    playerPos.y = 10.0f + logicSpace.y;
    player->setPosition(playerPos.x, playerPos.y);
    translateX += deltaTimeSeconds;

    glm::ivec2 resolution = window->GetResolution();


    visMatrix = glm::mat3(1);
    visMatrix *= VisualizationTransf2D(logicSpace, viewSpace);

    DrawScene(visMatrix);


    viewSpace = ViewportSpace(0, 0, resolution.x, resolution.y);
    SetViewportArea(viewSpace, glm::vec3(0), true);

    visMatrix = glm::mat3(1);
    visMatrix *= VisualizationTransf2DUnif(logicSpace, viewSpace);
    DrawScene(visMatrix);

    glm::ivec2 cursorPos = window->GetCursorPosition();
    cursorPos.y = window->GetResolution().y - window->GetCursorPosition().y;
    cursorPos.x -= window->GetResolution().x / 2;
    cursorPos.y -= window->GetResolution().y / 2;


    angularStep = atan2(cursorPos.y, cursorPos.x);
    
    /*
    
    Verificare COliziune Player Harta
    
    */
    if (playerPos.x < -11 + player->getRadius()) {
        playerPos.x = -11 + player->getRadius();
    }
    if (playerPos.x > 49 - player->getRadius()) {
        playerPos.x = 49 - player->getRadius();
    }

    if (playerPos.y < 0 + player->getRadius()) {
        playerPos.y = 0 + player->getRadius();
    }

    if (playerPos.y > 40 - player->getRadius()) {
        playerPos.y = 40 - player->getRadius();
    }

    if (logicSpace.x < -26 + player->getRadius()) {
        logicSpace.x = -26 + player->getRadius();
    }
    if (logicSpace.x > 34 - player->getRadius()) {
        logicSpace.x = 34 - player->getRadius();
    }

    if (logicSpace.y < -10 + player->getRadius()) {
        logicSpace.y = -10 + player->getRadius();
    }

    if (logicSpace.y > 30 - player->getRadius()) {
        logicSpace.y = 30 - player->getRadius();
    }


    /*
    
    Verificare coliziune Player Obstacol

    */

     for (int i = 0; i < 46; i++) 
     {
         collisions::Collision collision = collisions::CheckPOCollision(player, obstacles[i]);
         if (std::get<0>(collision))
         {
             collisions::Direction dir = std::get<1>(collision);
             glm::vec2 diff_vector = std::get<2>(collision);
             if (dir == collisions::LEFT)
             {
                float penetration = player->getRadius() - std::abs(diff_vector.x);
          
                     logicSpace.x += penetration;
             }
             else if (dir == collisions::RIGHT)
             {

                 float penetration = player->getRadius() - std::abs(diff_vector.x);

                 logicSpace.x -= penetration;
             }
             else if (dir == collisions::UP)
             {

                 float penetration = player->getRadius() - std::abs(diff_vector.y);

                 logicSpace.y -= penetration;
             }
             else
             {

                 float penetration = player->getRadius() - std::abs(diff_vector.y);

                 logicSpace.y += penetration;
             }
         }
     }

    /*
    
    Randare Player
    
    */

     modelMatrix = visMatrix *
         transform2D::Translate(playerPos.x, playerPos.y) *
         transform2D::Rotate(angularStep - 0.8f) *
         transform2D::Translate(-15.0f, -10.0f) *
         transform2D::Translate(1.35f, 0.9f) *
         transform2D::Translate(14.5, 9.3) *
         transform2D::Scale(0.4f, 0.4f);
     RenderMesh2D(meshes["circle1"], shaders["VertexColor"], modelMatrix);

     modelMatrix = visMatrix *
         transform2D::Translate(playerPos.x, playerPos.y) *
         transform2D::Rotate(angularStep + 0.4f) *
         transform2D::Translate(-15.0f, -10.0f) *
         transform2D::Translate(1.35f, 0.9f) *
         transform2D::Translate(14.5, 9.3) *
         transform2D::Scale(0.4f, 0.4f);
     RenderMesh2D(meshes["circle1"], shaders["VertexColor"], modelMatrix);

     modelMatrix = visMatrix *
         transform2D::Translate(playerPos.x, playerPos.y) *
         transform2D::Rotate(angularStep - 0.8f) *
         transform2D::Translate(-15.0f, -10.0f) *
         transform2D::Translate(1.35f, 0.9f) *
         transform2D::Translate(14.5, 9.3) *
         transform2D::Scale(0.4f, 0.4f);
     RenderMesh2D(meshes["circle2"], shaders["VertexColor"], modelMatrix);


     modelMatrix = visMatrix *
         transform2D::Translate(playerPos.x, playerPos.y) *
         transform2D::Rotate(angularStep + 0.4f) *
         transform2D::Translate(-15.0f, -10.0f) *
         transform2D::Translate(1.35f, 0.9f) *
         transform2D::Translate(14.5, 9.3) *
         transform2D::Scale(0.4f, 0.4f);
     RenderMesh2D(meshes["circle2"], shaders["VertexColor"], modelMatrix);


    modelMatrix = visMatrix * transform2D::Translate(playerPos.x, playerPos.y) *
        transform2D::Rotate(angularStep);
    RenderMesh2D(meshes["circle1"], shaders["VertexColor"], modelMatrix);


   


    /*

   Randare HealthBar

   */
    modelMatrix = visMatrix * transform2D::Translate(logicSpace.x, logicSpace.y) *
        transform2D::Translate(25.5f, 17.0f) *
        transform2D::Scale(5.0f, 1.5f);
    RenderMesh2D(meshes["hBar2"], shaders["VertexColor"], modelMatrix);

    for (int i = 0; i < player->getHealth(); i++) {
        modelMatrix = visMatrix * transform2D::Translate(logicSpace.x, logicSpace.y) *
            transform2D::Translate(30.0f - (float) i / 2, 17.0f) *
            transform2D::Scale(0.5f, 1.5f);
        RenderMesh2D(meshes["hBar"], shaders["VertexColor"], modelMatrix);
    }

    /*
    
    Randare Proiectile
    
    */

  
    if (weapon.size() > 0) {

        for (i = weapon.begin(); i < weapon.end();) {
            i->setAirTime(deltaTimeSeconds);
            i->setTranslateX(deltaTimeSeconds);
            i->setTranslateY(deltaTimeSeconds);
            i->setModelMatrix(visMatrix, i->getAngle());
            i->setRealPos();
    /*

    Verificare COliziune Proiectil Obstacol

    */
            for (int k = 0; k < 46; k++) {
                if (collisions::CheckPrOCollision(i, obstacles[k])) {
                    i->setSpawn(false);
                }
            }

    /*

    Verificare COliziune Proiectil Inamic

    */
            if (enemies.size() > 0) {
                for (j = enemies.begin(); j < enemies.end(); j++) {
                    if (collisions::CheckPrECollision(i, j)) {
                        i->setSpawn(false);
                        j->setHealth(0);
                        score++;
                        showScore = true;
                    }
                }
            }

    /*

    Verificare COliziune Proiectil Obstacol

    */


            if (i->getRealPos().x < -11 ||
                i->getRealPos().x > 49 ||
                i->getRealPos().y < 0 ||
                i->getRealPos().y > 40) {
                i->setSpawn(false);
            }
           if (i->getAirTime() > 5 || !i->getSpawn()) {
                i = weapon.erase(i);
            }
            else {

               RenderMesh2D(meshes["projectile"], shaders["VertexColor"], i->getModelMatrix());

                ++i;
            }
        }
    } 

    /*
    
    Randare Inamici

    */

    wave += deltaTimeSeconds;
    if (wave > 5) {
        for (int k = 0; k < 4; k++) {
            Enemy enemy;
            enemy.setPlayerPos(playerPos.x, playerPos.y);
            enemy.setSpeed();
            enemy.setAngle();
            enemy.setInitialPos();
            enemy.setTrajectory(enemy.getInitialPos());
            enemy.setModelMatrix(visMatrix);
            enemy.setPosition();
            enemies.push_back(enemy);
        }
        wave = 0;
    }
    
   
    if (enemies.size() > 0) {

        for (j = enemies.begin(); j < enemies.end();) {
            j->setPlayerPos(playerPos.x, playerPos.y);
            j->setTrajectory(j->getPosition());
            j->setTranslate(deltaTimeSeconds);
            j->setAngle();
            j->setModelMatrix(visMatrix);
            j->setPosition();

            if (collisions::CheckEPCollision(player, j))
            {
                j->setHealth(0);
                player->setHealth(player->getHealth() - 1);
            }
            

            if (j->getHealth() < 1) {
                j = enemies.erase(j);
            }
            else {

                RenderMesh2D(meshes["enemy1"], shaders["VertexColor"], j->getModelMatrix1());
                RenderMesh2D(meshes["enemy2"], shaders["VertexColor"], j->getModelMatrix2());
                RenderMesh2D(meshes["enemy2"], shaders["VertexColor"], j->getModelMatrix3());

                ++j;
            }
        }
    }

}


void Tema1::FrameEnd()
{
}


void Tema1::DrawScene(glm::mat3 visMatrix)
{
    //obstacole
    for (int i = 0; i < 46; i++)
    {
        obstacles[i].setModelMatrix(visMatrix);
        RenderMesh2D(meshes["obstacle"], shaders["VertexColor"], obstacles[i].getModelMatrix());
        RenderMesh2D(meshes["obstacle2"], shaders["VertexColor"], obstacles[i].getModelMatrix());
    }

 
    
    //harta
    modelMatrix = visMatrix * transform2D::Translate(-11.0f, 0.0f) *
        transform2D::Scale(60.0f, 40.0f);
    RenderMesh2D(meshes["harta2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = visMatrix * transform2D::Translate(-11.5f, -0.5f) *
        transform2D::Scale(61.0f, 0.5f);
    RenderMesh2D(meshes["harta"], shaders["VertexColor"], modelMatrix);

    modelMatrix = visMatrix * transform2D::Translate(-11.5f, 40.0f) *
        transform2D::Scale(61.0f, 0.5f);
    RenderMesh2D(meshes["harta"], shaders["VertexColor"], modelMatrix);

    modelMatrix = visMatrix * transform2D::Translate(-11.5f, 0.0f) *
        transform2D::Scale(0.5f, 40.0f);
    RenderMesh2D(meshes["harta"], shaders["VertexColor"], modelMatrix);

    modelMatrix = visMatrix * transform2D::Translate(49.0f, 0.0f) *
        transform2D::Scale(0.5f, 40.0f);
    RenderMesh2D(meshes["harta"], shaders["VertexColor"], modelMatrix);

}



void Tema1::OnInputUpdate(float deltaTime, int mods)
{
    if (window->KeyHold(GLFW_KEY_W))
        logicSpace.y += deltaTime * 10;
    if (window->KeyHold(GLFW_KEY_S))
        logicSpace.y -= deltaTime * 10;

    if (window->KeyHold(GLFW_KEY_A))
        logicSpace.x -= deltaTime * 10;
    if (window->KeyHold(GLFW_KEY_D))
        logicSpace.x += deltaTime * 10;
}


void Tema1::OnKeyPress(int key, int mods)
{
}



void Tema1::OnKeyRelease(int key, int mods)
{
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_2 && fireRate < Engine::GetElapsedTime()) {
        fireRate = Engine::GetElapsedTime() + player->getReloadTime();
        Projectile projectile;
        int revMouseY = window->GetResolution().y - mouseY;
        projectile.setAngle(angularStep);
        projectile.setPlayerPos(playerPos.x, playerPos.y);
        projectile.setInitialPos(window->GetResolution().x / 2, window->GetResolution().y / 2);
        projectile.setTrajectory(mouseX, revMouseY);
        projectile.setModelMatrix(visMatrix, angularStep);
        weapon.push_back(projectile);
    }
    
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

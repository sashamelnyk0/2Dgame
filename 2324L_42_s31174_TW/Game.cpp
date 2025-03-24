#include "Game.h"


void Game::initVariables() {
    this->window = nullptr;


    if (!this->map.loadFromFile("D:\\sakura2.jpg")) {
        std::cerr << "Failed to load background texture" << std::endl;
    }
    this->backgroundSprite.setTexture(map);

    if (!this->font.loadFromFile("D:\\font.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    this->scoreText.setFont(font);
    this->scoreText.setCharacterSize(50);
    this->scoreText.setFillColor(sf::Color::Black);
    this->scoreText.setPosition(20.f, 20.f);

    this->hpText.setFont(font);
    this->hpText.setCharacterSize(50);
    this->hpText.setFillColor(sf::Color::Black);
    this->hpText.setPosition(1000.f, 20.f);


    this->gameOver.setFont(font);
    this->gameOver.setCharacterSize(100);
    this->gameOver.setFillColor(sf::Color::Black);
    this->gameOver.setPosition(600, 400);

}

void Game::initWindow() {

    this->videoMode.height = 800;
    this->videoMode.width = 1200;
    this->window = new sf::RenderWindow(this->videoMode, "GokuFight", sf::Style::Default, sf::ContextSettings(0, 0, 8));
    this->window->setFramerateLimit(60);
}


Game::Game() : score(0), hp(100){
    this->initVariables();
    this->initWindow();
    this->initTextures();
    this->hpText.setString("Hp: " + std::to_string(this->hp));
    this->scoreText.setString("Score: " + std::to_string(this->score));
    this->enemyFar = false;
    loadBestScore();
}

Game::~Game() {
    delete this->window;

    // Delete textures
    for (auto& i : this->textures) {
        delete i.second;
    }

    // Delete bullets
    for (auto* i : this->bullets) {
        delete i;
    }
    for (auto* i : this->enemBullets) {
        delete i;
    }

    // Delete enemies
    for (auto* i : this->enemies) {
        delete i;
    }
    for (auto* i : this->enemies2) {
        delete i;
    }
    for (auto* i : this->perks) {
        delete i;
    }
    for (auto* i : this->icons) {
        delete i;
    }


}
int Game::getBestScore() const {
    return bestscore;
}

void Game::setBestScore(int score) {
    if (score > bestscore) {
        bestscore = score;
    }
}

void Game::saveBestScore() const {
    std::ofstream file(scoreFile);
    if (file.is_open()) {
        file << bestscore;
        file.close();
    } else {
        std::cerr << "Unable to open file for writing best score." << std::endl;
    }
}

void Game::loadBestScore() {
    std::ifstream file(scoreFile);
    if (file.is_open()) {
        file >> bestscore;
        file.close();
    } else {
        std::cerr << "Unable to open file for reading best score, initializing to 0." << std::endl;
        bestscore = 0;
    }
}


const bool Game::running() const {
    return this->window->isOpen();
}

// Functions
void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        if (ev.type == sf::Event::Closed) {
            this->window->close();
        }
    }
}

void Game::update() {
    this->pollEvents();

        this->updateInput();
        this->updateBullet();
        this->updateEnemy();
        this->updatePerks();
        this->updateCombat();
        this->endGame();
        this->updateEnemyAtack();
        this->player.update();

}

void Game::initTextures() {
    this->textures["BULLET"] = new sf::Texture();
    if (!this->textures["BULLET"]->loadFromFile("D:\\Bullet.png")) {
        std::cerr << "Failed to load bullet texture" << std::endl;
    }
    this->textures["BULLET2"] = new sf::Texture();
    if (!this->textures["BULLET2"]->loadFromFile("D:\\enemBullet1.png")) {
        std::cerr << "Failed to load bullet texture" << std::endl;
    }
    this->textures["ENEMY1"] = new sf::Texture();
    if (!this->textures["ENEMY1"]->loadFromFile("D:\\enem11.png")) {
        std::cerr << "Failed to load enemy texture" << std::endl;
    }
    this->textures["ENEMY2"] = new sf::Texture();
    if (!this->textures["ENEMY2"]->loadFromFile("D:\\enem22.png")) {
        std::cerr << "Failed to load enemy texture" << std::endl;
    }
    this->textures["PERK"] = new sf::Texture();
    if (!this->textures["PERK"]->loadFromFile("D:\\element.png")) {
        std::cerr << "Failed to load enemy texture" << std::endl;
    }
    this->textures["RUN"] = new sf::Texture();
    if (!this->textures["RUN"]->loadFromFile("D:\\fastrun1.png")) {
        std::cerr << "Failed to load enemy texture" << std::endl;
    }
    this->textures["SHOOT"] = new sf::Texture();
    if (!this->textures["SHOOT"]->loadFromFile("D:\\fastshoot1.png")) {
        std::cerr << "Failed to load enemy texture" << std::endl;
    }
    this->textures["HEAL"] = new sf::Texture();
    if (!this->textures["HEAL"]->loadFromFile("D:\\heal1.png")) {
        std::cerr << "Failed to load enemy texture" << std::endl;
    }

}

void Game::updateBullet() {
    unsigned counter = 0;
    for (auto* bullet : this->bullets) {
        bullet->update();

        // Bullet delete
        if (bullet->getBounds().top + bullet->getBounds().height < 0.f ||
            bullet->getBounds().top + bullet->getBounds().height > 800 ||
            bullet->getBounds().left + bullet->getBounds().width < 0 ||
            bullet->getBounds().left + bullet->getBounds().width > 1200) {
            // Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            std::cout << "delete bullet" << std::endl;
            --counter;
        }
        ++counter;
    }
    for(auto*bullet:this->enemBullets){
        bullet->update();
    }
}
void Game::updatePerks() {
    float timeSpawn = 10.f;
    const float fastRunDuration = 5.f; // Тривалість швидкого бігу у секундах
    const float fastShootDuration = 5.f;

    // Spawn
    if (this->spawnElements.getElapsedTime().asSeconds() >= timeSpawn) {
        this->perks.push_back(new Perks(this->textures["PERK"]));
        this->spawnElements.restart();

    }

    for (size_t k = 0; k < perks.size(); ++k) {
        if (perks[k]->getBounds().intersects(player.getBounds())) {
            delete perks[k];
            perks.erase(perks.begin() + k);

            int random_number = std::rand() % 3 + 1;
            std::cout << random_number << std::endl;

            if (random_number == 1 && !player.isFastRun) {
                player.movementSpeed = 5.f;
                player.isFastRun = true;
                fastRunTimer.restart(); // Перезапускаємо таймер для швидкого бігу
                this->icons.push_back(new Icons(this->textures["RUN"]));
            }

            if (random_number == 2 && !player.isFastShoot) {
                player.attackCooldownMax = 3.f;
                player.isFastShoot = true;
                fastShootTimer.restart(); // Перезапускаємо таймер для швидкої атаки
                this->icons.push_back(new Icons(this->textures["SHOOT"]));

            }
            if(random_number == 3){
                hp += 50;
                if(hp>100){
                    hp = 100;
                }
                this->hpText.setString("Hp: " + std::to_string(this->hp));
                this->icons.push_back(new Icons(this->textures["HEAL"]));
            }
            break;
        }
    }

    // Perks
    if (player.isFastRun && fastRunTimer.getElapsedTime().asSeconds() > fastRunDuration) {
        player.movementSpeed = 2.f;
        player.isFastRun = false;


    }


    if (player.isFastShoot && fastShootTimer.getElapsedTime().asSeconds() > fastShootDuration) {
        player.attackCooldownMax = 10.f;
        player.isFastShoot = false;

    }
}

void Game::updateInput() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player.canAttack()) {
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player.getPos().x, this->player.getPos().y+50, this->player.getDirectionX(), this->player.getDirectionY()));
    }
}
void Game::updateEnemyAtack(){
    float timeEnemyAtack = 3.f;
    if (this->atackClock.getElapsedTime().asSeconds() >= timeEnemyAtack) {

        for (int i = this->enemies2.size() - 1; i >= 0; --i) {
            if (i < this->enemies2.size()) {

                this->enemBullets.push_back(new Bullet(this->textures["BULLET2"],this->enemies2[i]->getPos().x,this->enemies2[i]->getPos().y + 50,-1, 0));
            }
        }

        this->atackClock.restart();
    }
}

void Game::endGame() {
    if(this->hp<=0 || enemyFar){
        if(score>bestscore){
            setBestScore(score);
            saveBestScore();
        }
        this->window->close();
    }

}

void Game::updateEnemy() {
    // Update
    float timeSpawnCommon = 2.f;
    float timeSpawnArch = 5.f;

    // Spawn
    if (this->clock.getElapsedTime().asSeconds() >= timeSpawnCommon) {
        this->enemies.push_back(new Enemy(this->textures["ENEMY1"], 0.002f, rand() % 500 + 500, 1, 5.f));
        this->clock.restart();
    }
    if (this->clock2.getElapsedTime().asSeconds() >= timeSpawnArch) {
        this->enemies2.push_back(new Enemy2(this->textures["ENEMY2"], 0, rand() % 500 + 500, 1, 5.f));
        this->clock2.restart();
    }

    // Update
    for (int i = this->enemies.size() - 1; i >= 0; --i) {
        Enemy* enemy = this->enemies[i];
        enemy->update();

        // Enemy culling (out of bounds)
        if (enemy->getBounds().left + enemy->getBounds().width < 50.f) {
            this->enemyFar = true;
            std::cout << "end" << std::endl;
            delete enemy;
            this->enemies.erase(this->enemies.begin() + i);
        }
    }
    for (int i = this->enemies2.size() - 1; i >= 0; --i) {
        Enemy2* enemy2 = this->enemies2[i];
        enemy2->update();
    }
}

void Game::updateCombat() {
    for (size_t i = 0; i < this->enemies.size(); /* no increment here */) {
        bool enemy_deleted = false;


        for (size_t k = 0; k < this->bullets.size(); ++k) {
            if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())) {
                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);

                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);

                enemy_deleted = true;

                this->score += 100;
                std::cout << this->score << std::endl;
                this->scoreText.setString("Score: " + std::to_string(this->score));


                break;
            }
        }


        if (enemy_deleted) {
            continue;
        }

        if (this->enemies[i]->getBounds().intersects(this->player.getBounds())) {
            delete this->enemies[i];
            this->enemies.erase(this->enemies.begin() + i);

            this->hp -= 10;
            std::cout << this->hp << std::endl;
            this->hpText.setString("Hp: " + std::to_string(this->hp));

            continue;
        }

        ++i;
    }
    for (size_t k = 0; k < this->enemBullets.size(); ++k) {
        if (this->enemBullets[k]->getBounds().intersects(this->player.getBounds())) {
            delete this->enemBullets[k];
            this->enemBullets.erase(this->enemBullets.begin() + k);


            this->hp -= 10;
            std::cout << this->hp << std::endl;
            this->hpText.setString("Hp: " + std::to_string(this->hp));

            break;
        }
    }
    for (size_t i = 0; i < this->enemies2.size();) {
        bool enemy_deleted = false;

        // Check collision with bullets
        for (size_t k = 0; k < this->bullets.size(); ++k) {
            if (this->enemies2[i]->getBounds().intersects(this->bullets[k]->getBounds())) {
                delete this->enemies2[i];
                this->enemies2.erase(this->enemies2.begin() + i);

                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);

                enemy_deleted = true;

                this->score += 150;
                std::cout << this->score << std::endl;
                this->scoreText.setString("Score: " + std::to_string(this->score));


                break;
            }
        }

        ++i;
    }

}

void Game::render() {
    this->window->clear(sf::Color::Green);

    this->window->draw(this->backgroundSprite);

        // Draw game objects
        this->player.render(this->window);

        for (auto* bullet : this->bullets) {
            bullet->render(this->window);
        }
        for(auto* bullet:this->enemBullets){
            bullet->render(this->window);
        }
        for (auto* enemy : this->enemies) {
            enemy->render(this->window);
        }
        for (auto* enemy2 : this->enemies2) {
            enemy2->render(this->window);
        }
        for (auto* perk : this->perks) {
            perk->render(this->window);
        }
        for (auto* icons : this->icons) {
            icons->render(this->window);
        }
        this->window->draw(this->scoreText);
        this->window->draw(this->hpText);

    this->window->display();
}
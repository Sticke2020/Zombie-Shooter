#pragma

#include <SFML/Graphics.hpp>

using namespace sf;

class Player {
    // Private member variables
    private:
        const float START_SPEED = 200;
        const float START_HEALTH = 100;

        // Where is the player?
        Vector2f m_Position;

        // The sprite
        Sprite m_Sprite;

        // And a texture
        Texture m_Texture;

        // What is the screen resolution?
        Vector2f m_Resolution;

        // What is the size of the current arena?
        IntRect m_Arena;

        // How big is each tile of the arena?
        int m_Tilesize;

        // Which direction(s) the player is moving in
        bool m_UpPressed;
        bool m_DownPressed;
        bool m_RightPressed;
        bool m_LeftPressed;

        // How much health does the player have?
        int m_Health;

        // What is the max health the player can have?
        int m_MaxHealth;

        // When was the player last hit?
        Time m_LastHit;

        // Speed in pixels per second
        float m_Speed;
        
    // Public functions
    public:
        Player();
        void spawn(IntRect arena, Vector2f resolution, int tileSize);

        // Call this at the end of every game
        void resetPlayerStats();

        // Handle the player getting hit by a zombie
        bool hit(Time timeHit);

        // How long ago was the player last hit?
        Time getLastHitTime();

        // Where is the player?
        FloatRect getPosition();

        // Where is the center of the player?
        Vector2f getCenter();

        // What angle is the player facing?
        float getRotation();

        // Send a copy of the sprite to the main function
        Sprite getSprite();

        // The next four functions move the player
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        // Stop the player moving in each direction
        void stopLeft();
        void stopRight();
        void stopUp();
        void stopDown();

        // We will call this function once per frame
        void update(float elapsedTime, Vector2i mousePosition);

        // Give the player a speed boost
        void upgradeSpeed();

        // Increase the max helath the player can have
        void upgradeHealth();

        // Give the player some health
        void increaseHealthLevel(int amount);

        // How much health does the player currently have?
        int getHealth();
};
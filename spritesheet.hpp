
#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp> // TODO remove import
#include <iostream>

class SpriteSheet : public sf::Drawable, public sf::Transformable
{
public:
    SpriteSheet();
    SpriteSheet(const std::string &file_name, int tile_size)
        : m_file_name(file_name), m_tile_size(tile_size) {}

    bool subdivide();
    void draw_board(const int *tiles, int height, int width);

    // Getters to Access SpriteSheet info
    sf::Texture &get_tileset_texture()
    {
        return m_tilesetTexture;
    }
    int get_tile_size()
    {
        return m_tile_size;
    }
    int get_sheet_width()
    {
        return m_tileset_cols;
    }
    int get_sheet_height()
    {
        return m_tileset_rows;
    }

private:
    sf::Texture m_tilesetTexture;       // Sprite sheet image texture
    const std::string &m_file_name;
    int m_tile_size;                    // width/height of single tile in pixels
    int m_tileset_cols;
    int m_tileset_rows;

    sf::VertexArray m_drawn_tiles;      // Tiles that are drawn by user

    // Sprite Sheet V1
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tilesetTexture;

        // draw the vertex array
        target.draw(m_drawn_tiles, states);
    }
};

#endif // SPRITESHEET_H
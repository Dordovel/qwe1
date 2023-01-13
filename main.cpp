#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>
#include <utility>

#include "anim.hpp"
#include "dynamic.hpp"
#include "header/ground.hpp"
#include "header/sprite_factory.hpp"
#include "keyboard.hpp"
#include "main.hpp"
#include "object.hpp"
#include "rect.hpp"
#include "rex.hpp"

sf::Sprite make_ground_from_texture(const project::SpriteFactory& factory)
{
    sf::Vector2i tilesetSize(factory.size());
    sf::Sprite ground(factory.make_from_texture(tilesetSize.y - 25, 0, tilesetSize.x, 42));

    return ground;
}

sf::FloatRect get_view_bound(const sf::View& view)
{
    sf::Vector2f center = view.getCenter();
    sf::Vector2f size = view.getSize();

    int x = static_cast<int>(size.x) >> 1;
    int y = static_cast<int>(size.y) >> 1;

    float top = center.y - y;
    float left = center.x - x;

    return {left, top, size.x, size.y};
}

int main (int argc, char *argv[])
{
    sf::RenderWindow wnd(sf::VideoMode(600, 800), "View");

    sf::Texture tileset;
    tileset.loadFromFile("./resources/offline-sprite-2x.png");

    project::SpriteFactory factory(tileset);
    sf::Sprite groundSprite = make_ground_from_texture(factory);

    project::Ground ground(std::make_unique<project::Object>(std::move(groundSprite)));
    sf::FloatRect bound = ::get_view_bound(wnd.getView());
    ground.init(bound.left, bound.top, bound.width, bound.height);

    sf::Sprite dino(factory.make_from_texture(0, 1340, 90, 100));
    auto obj = project::Anim(std::move(dino));

    for(int x = 1340, frame = 0; frame < 4;x += 88, ++frame)
    {
        obj.addFrame(project::IRect(sf::IntRect{x, 0, 90, 100}), 0.04);
    }

    auto rex = std::make_unique<project::Rex>(std::move(obj));

    project::Main main(std::move(rex));

    ground.add_sublayout(&main);

    sf::Clock clock;
    sf::Time timer;

    while (wnd.isOpen())
    {
        sf::Event event;
        while (wnd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                wnd.close();

            switch (event.type)
            {
                case sf::Event::Closed:
                    wnd.close();
                break;
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_ESCAPE, true);
                        break;
                        case sf::Keyboard::Down:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_DOWN, true);
                        break;
                        case sf::Keyboard::Up:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_UP, true);
                        break;
                        case sf::Keyboard::Left:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_LEFT, true);
                        break;
                        case sf::Keyboard::Right:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_RIGHT, true);
                        break;
                        case sf::Keyboard::Space:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_SPACE, true);
                        break;
                        case sf::Keyboard::Return:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_RETURN, true);
                        break;
                        default: break;
                    }
                break;
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_ESCAPE, false);
                        break;
                        case sf::Keyboard::Down:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_DOWN, false);
                        break;
                        case sf::Keyboard::Up:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_UP, false);
                        break;
                        case sf::Keyboard::Left:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_LEFT, false);
                        break;
                        case sf::Keyboard::Right:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_RIGHT, false);
                        break;
                        case sf::Keyboard::Space:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_SPACE, false);
                        break;
                        case sf::Keyboard::Return:
                            project::Keyboard::on_key_event(project::Keyboard::Keys::VK_RETURN, false);
                        break;
                        default: break;
                    }
                break;
                default: break;
            }
        }

        wnd.clear(sf::Color(255, 255, 255));
        timer = clock.restart();
        ground.update(timer.asSeconds());
        sf::FloatRect bound = ::get_view_bound(wnd.getView());
        ground.update_view(bound.left, bound.top, bound.width, bound.height);
        ground.draw(&wnd);

        wnd.display();
    }

    return 0;
}

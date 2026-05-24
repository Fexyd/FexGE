//
// Created by fexyd on 20/05/26.
//

#include "../Window.h"
#include <SFML/Graphics.hpp>


struct FexGE::Plataform::CWindow::Impl
{
    sf::RenderWindow window;
    int w;
    int h;
    std::pmr::string name;
};


// Constructor
FexGE::Plataform::CWindow::CWindow(int w, int h, const std::string& title) : m_impl(std::make_unique<Impl>())
{
    m_impl->window.create(sf::VideoMode(w, h), title);
}

// Destructor
FexGE::Plataform::CWindow::~CWindow() = default;


// GetImpl
FexGE::Plataform::CWindow::Impl* FexGE::Plataform::CWindow::getImpl()
{
    return m_impl.get();
}

//PUBLIC FUNCS -------

// WINDOW
void FexGE::Plataform::CWindow::create_Window()
{
    sf::RenderWindow& window = m_impl->window;
}

bool FexGE::Plataform::CWindow::win_is_open()
{
    // Procesar eventos básicos para que la X funcione
    sf::Event event;
    while (m_impl->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_impl->window.close();
            return false;
        }
    }

    return m_impl->window.isOpen();
}

void FexGE::Plataform::CWindow::win_close()
{
    m_impl->window.close();
}


// RENDER

void FexGE::Plataform::CWindow::win_draw(int vertexCount, std::vector<float>& vertexArray, float posX, float posY)
{
    // Verificaciones rápidas
    if (vertexArray.empty()) return;
    if (vertexCount < 3) return;
    if (vertexArray.size() != vertexCount * 2) return;

    // Convertir a SFML
    sf::ConvexShape shape;
    shape.setPointCount(vertexCount);

    // Calcular centro y aplicar posición
    for (int i = 0; i < vertexCount; i++)
    {
        float x = vertexArray[i * 2] + posX;
        float y = vertexArray[i * 2 + 1] + posY;
        shape.setPoint(i, sf::Vector2f(x, y));
    }

    // Dibujar
    m_impl->window.draw(shape);
}

void FexGE::Plataform::CWindow::win_display()
{
    m_impl->window.display();
}

void FexGE::Plataform::CWindow::win_clear()
{
    m_impl->window.clear();
}


// INPUT

void FexGE::Plataform::CWindow::win_pollEvent()
{
    sf::Event event;
    while (m_impl->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_impl->window.close();
        }
        // Los demas eventos se ignoran o se guardan para input
    }
}

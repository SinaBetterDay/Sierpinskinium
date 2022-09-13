#ifndef SFML_RECTANGLESHAPE_HPP
#define SFML_RECTANGLESHAPE_HPP  
// Headers
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Shape.hpp>


namespace sf
{
class SFML_GRAPHICS_API RectangleShape : public Shape 
{
public:

   explicit RectangleShape(const Vector2f& size = Vector2f(0, 0));
    
   void setSize(const Vector2f& size);
    
        const Vector2f& getSize() const;
    
       virtual std::size_t getPointCount() const;
   
       virtual Vector2f getPoint(std::size_t index) const;
   
   private:
   
      // Member data
      Vector2f m_size; 
  };
  } // namespace sf

#endif // SFML_RECTANGLESHAPE_HPP

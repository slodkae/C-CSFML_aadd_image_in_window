#include <SFML/Graphics.h>

static sfRenderWindow * create_renderwindow(unsigned int x, unsigned int y
, unsigned int bpp, char *title) 
{
    sfVideoMode video_mode = {x, y, bpp};
    
    return (sfRenderWindow_create(video_mode, "My first Window", sfClose | sfResize, NULL));

}

int main()
{
    sfRenderWindow *window = create_renderwindow(1920, 1080, 32, "Let's draw !");
    sfEvent event;
    sfTexture *my_texture = sfTexture_createFromFile("my_img.jpeg", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f my_pos = {400, 200};
    sfVector2f scale = {4, 4};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);  
        sfRenderWindow_drawSprite(window, my_sprite, NULL);
        }
    }
}

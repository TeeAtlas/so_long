#include "so_long.h"

void printsplit(t_game *game)
{
    int i = 0;
    int j = 0;
    
    while (game->map.array[i])
    {
        j = 0;
        while (game->map.array[i][j])
        {
            ft_printf("%c", game->map.array[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
 

int main(void)
{
	t_game *game;
	
 	printsplit(game->map.array[5][10]);
 	return(0);
}
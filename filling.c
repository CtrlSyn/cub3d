/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulai <ansoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:52:53 by ansoulai          #+#    #+#             */
/*   Updated: 2024/10/27 18:03:50 by ansoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_into_tab(t_data *data)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = data->width;
	data->tab = malloc((data->height + 1) * sizeof(char *));
	if (!data->tab)
	{
		free(data->lines);
		exit_with_message("fail Allocation");
	}
	while (i < data->height)
	{
		data->tab[i] = ft_substr(data->lines, start, end, data);
		i++;
		start += data->width;
		end += data->width;
	}
	data->tab[data->height] = NULL;
	free(data->lines);
}

void initialize_mlx(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, data->width * 32,
			data->height * 32, "cub3d");
	data->mlx_image = mlx_new_image(data->mlx, data->width * 32,
			data->height * 32);
	
}

void draw_map(t_data *data)
{
	int i;
	int j;
	int pixel_x;
	int pixel_y;
	void *img;
	int *addr;

	img = mlx_new_image(data->mlx, data->width * 32, data->height * 32);
	addr = (int *)mlx_get_data_addr(img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	i = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			pixel_x = j * 32;  
			pixel_y = i * 32;  

			if (data->tab[i][j] == '1')
			{
				for (int y = 0; y < 32; y++)
				{
					for (int x = 0; x < 31; x++)
					{
						addr[(pixel_y + y) * data->width * 32 + (pixel_x + x)] = 0x0000FF;
					}
				}
			}
			else if (data->tab[i][j] == '0')
			{
				for (int y = 0; y < 32; y++)
				{
					for (int x = 0; x < 31; x++)
					{
						addr[(pixel_y + y) * data->width * 32 + (pixel_x + x)] = 0xFFFF00;
					}
				}
			}
			else if (data->tab[i][j] == 'P')
			{
				for (int y = 0; y < 32; y++)
				{
					for (int x = 0; x < 31; x++)
					{
						addr[(pixel_y + y) * data->width * 32 + (pixel_x + x)] = 0xff3300;
					}
				}
			}
		j++;
	}
	i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, 0, 0);

}



int key_handler(int key, t_data *data)
{
    printf("Received key: %d\n", key); 

    if (key == ESC_KEY)
    {
        close_window(data);
        exit(0);
    }
    if (key == W)
    {
        printf("W pressed\n ==> %d\n", key);
        move_up(data);
    }
	if (key == A)
    {
        printf("A pressed\n ==> %d\n", key);
        move_left(data);
    }
	if (key == D)
    {
        printf("D pressed\n ==> %d\n", key);
        move_right(data);
    }
	if (key == S)
    {
        printf("S pressed\n ==> %d\n", key);
        move_down(data);
    }
    return (0);
}

void	move_up(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			
			if (data->tab[data->i][j] == 'P')
			{
				if (data->tab[data->i - 1][j] == '1')
					return ;
				data->tab[data->i][j] = '0';
				data->tab[data->i - 1][j] = 'P';
				draw_map(data);
				return ;
			}
		}
	}
}
void	move_left(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			
			if (data->tab[data->i][j] == 'P')
			{
				if (data->tab[data->i][j - 1] == '1')
					return ;
				data->tab[data->i][j] = '0';
				data->tab[data->i][j - 1] = 'P';
				draw_map(data);
				return ;
			}
		}
	}
}
void	move_right(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			
			if (data->tab[data->i][j] == 'P')
			{
				if (data->tab[data->i][j + 1] == '1')
					return ;
				data->tab[data->i][j] = '0';
				data->tab[data->i][j + 1] = 'P';
				draw_map(data);
				return ;
			}
		}
	}
}
void	move_down(t_data *data)
{
	int	j;

	data->i = -1;
	while (data->tab[++data->i])
	{
		j = -1;
		while (data->tab[data->i][++j])
		{
			
			if (data->tab[data->i][j] == 'P')
			{
				if (data->tab[data->i + 1][j] == '1')
					return ;
				data->tab[data->i][j] = '0';
				data->tab[data->i + 1][j] = 'P';
				draw_map(data);
				return ;
			}
		}
	}
}

void draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_pixel_put(data->mlx, data->mlx_image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	// free_map(data);
	return (1);
}

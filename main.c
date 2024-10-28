/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulai <ansoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:15:50 by ansoulai          #+#    #+#             */
/*   Updated: 2024/10/27 15:29:44 by ansoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int ac, char **av)
{
    t_data data;
    if(ac != 2)
    {
        printf("Error\nWrong number of arguments\n");
        return (1);
    }
    
    check_path(av[1]);
    fetch(av[1], &data);
    fill_into_tab(&data);
    data.mlx = mlx_init();
    initialize_mlx(&data);
    draw_map(&data);
    mlx_key_hook(data.mlx_win, key_handler, &data);

    mlx_loop(data.mlx);

    return (0);
}

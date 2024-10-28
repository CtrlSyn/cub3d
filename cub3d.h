/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulai <ansoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:54:38 by ansoulai          #+#    #+#             */
/*   Updated: 2024/10/27 17:48:37 by ansoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D
# define CUB3D

# include "includes/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libraries/mlx/mlx.h"



#ifdef __APPLE__
    // macOS keycodes
    # define ESC_KEY        53
    # define W              13
    # define A              0
    # define S              1
    # define D              2
    
    
    
    # define MOVE_SPEED     0.08     // player speed
    # define ROT_SPEED      0.04     // Rotation speed (in radians)

#elif __linux__
    // Linux (X11) keycodes
    # define ESC_KEY        65307
    # define U_KEY          65362
    # define D_KEY          65364
    # define R_KEY          6536301
    # define L_KEY          65361
    
    # define MOVE_SPEED     0.04     // player speed
    # define ROT_SPEED      0.02     // Rotation speed (in radians)
#else
    #error "Unsupported platform"
#endif


typedef struct s_data
{
    int height;
    int width;
    char **tab;
    char *line;
    char *lines;
    void *mlx;
    void *mlx_win;
    void *mlx_image;
    int i;
    int j;
    int bits_per_pixel;
    int line_length;
    int endian;

}           t_data;

// Parsing functions :
void fetch(char *av, t_data *data);
int check_path(char *av);
void	loop_over_map(t_data *data, int fd);

// Utils functions :
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen_w_nl(char *str);
void    exit_with_message(char *message);
char	*ft_substr(char *src, int start, int end, t_data *data);

// Filling functions :
void	fill_into_tab(t_data *data);
void initialize_mlx(t_data *data);
void draw_map(t_data *data);
void draw_square(t_data *data, int x, int y, int color);
int	key_handler(int key, t_data *data);
int	close_window(t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);

#endif
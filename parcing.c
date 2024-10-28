/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulai <ansoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:53:33 by ansoulai          #+#    #+#             */
/*   Updated: 2024/10/25 12:33:53 by ansoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void fetch(char *av, t_data *data)
{
    int fd;
    char *line;
    data->lines = NULL;
    data->height = 0;

    fd = open(av, O_RDONLY);
    if (fd < 0)
        exit_with_message("File not found");
    data->line = get_next_line(fd);
    data->width = (int)ft_strlen_w_nl(data->line);
    if(!data->width)
    {
        free(data->line);
        free(data->lines);
        exit_with_message("Empty file");
    }
    if (data->line[(int)ft_strlen(data->line) - 1] == '\n')
	{
		line = data->line;
		data->line = ft_substr(data->line, 0, data->width, data);
		free(line);
	}
    loop_over_map(data, fd);
}

void	loop_over_map(t_data *data, int fd)
{
	char	*line;

	while (data->line != NULL)
	{
		data->height++;

		if (data->line[(int)ft_strlen(data->line) - 1] == '\n')
		{
			line = data->line;
			data->line = ft_substr(data->line, 0, data->width, data);
			free(line);
		}
		data->lines = ft_strjoin(data->lines, data->line);
		free(data->line);
		data->line = get_next_line(fd);
	}
	free(data->line);
	close(fd);
}

int check_path(char *av)
{
    if (ft_strncmp(av + ft_strlen(av) - 4, ".cub", 4) != 0)
        exit_with_message("Wrong file extension");
    return (0);
}
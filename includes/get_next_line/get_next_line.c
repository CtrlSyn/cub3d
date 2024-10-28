/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulai <ansoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:43:32 by ansoulai          #+#    #+#             */
/*   Updated: 2024/06/08 00:35:03 by ansoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_archive(char *archive)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (archive[i] && archive[i] != '\n')
		i++;
	if (!archive[i])
	{
		free(archive);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(archive) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (archive[i])
		str[j++] = archive[i++];
	str[j] = '\0';
	free(archive);
	return (str);
}

char	*ft_get_line(char *archive)
{
	int		i;
	char	*str;

	i = 0;
	if (!archive[i])
		return (NULL);
	while (archive[i] && archive[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (archive[i] && archive[i] != '\n')
	{
		str[i] = archive[i];
		i++;
	}
	if (archive[i] == '\n')
	{
		str[i] = archive[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_to_archive(int fd, char *archive)
{
	char	*buff;
	ssize_t	rd_bytes;

	buff = malloc((size_t)BUFFER_SIZE * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(archive, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			if (archive != NULL)
				free(archive);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		archive = ft_strjoin(archive, buff);
	}
	free(buff);
	return (archive);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*archive;

	archive = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	archive = ft_read_to_archive(fd, archive);
	if (!archive)
		return (NULL);
	line = ft_get_line(archive);
	return (free(archive), line);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("filename.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	line = get_next_line(fd);
// 	while(line != NULL)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);

// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansoulai <ansoulai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:19:31 by ansoulai          #+#    #+#             */
/*   Updated: 2024/10/25 11:47:15 by ansoulai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (i == n)
        return (0);
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
size_t	ft_strlen_w_nl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void exit_with_message(char *message)
{
    printf("Error\n%s\n", message);
    exit(1);
}

char	*ft_substr(char *src, int start, int end, t_data *data)
{
	int		i;
	char	*new_str;
	(void)data;

	if (!src)
		return (NULL);
	i = 0;
	new_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (new_str == NULL)
	{
		// free_map(data);
		exit(0);
	}
	while (start < end)
	{
		new_str[i] = src[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

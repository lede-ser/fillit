/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:45:08 by eebersol          #+#    #+#             */
/*   Updated: 2016/03/19 17:04:28 by lede-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char	*ft_read_map(char *file)
{
	int		fd;
	char	*buff;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	if ((read(fd, buff, BUFF_SIZE)) < 0)
		ft_error();
	if (ft_strlen(buff) < 20 || buff[BUFF_SIZE - 1] != '\0')
		ft_error();
	if (buff[ft_strlen(buff) - 2] == '\n')
		ft_error();
	if (buff[0] == '\n')
		ft_error();
	close(fd);
	return (buff);
}

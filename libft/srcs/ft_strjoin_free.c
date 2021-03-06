/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:12:33 by gduval            #+#    #+#             */
/*   Updated: 2016/11/24 15:29:16 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin_free(char const *s1, char const *s2, int option)
{
	char	*str;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = ft_strnew(len)))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		if (option == 1 || option == 3)
			ft_strdel((char **)&s1);
		if (option == 2 || option == 3)
			ft_strdel((char **)&s2);
		return (str);
	}
	return (NULL);
}

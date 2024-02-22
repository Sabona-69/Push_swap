/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:55:09 by hel-omra          #+#    #+#             */
/*   Updated: 2024/02/22 04:33:36 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	custom_atoi(char *s)
{
	long		res;
	long		sign;

	res = 0;
	sign = 1;
	while (*s == 32 || (*s <= 9 && *s >= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s == '+' || *s == '-' || *s == '\0' || *s == ' ')
		ft_error();
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		s++;
		if ((res * sign) < -2147483648 || (res * sign) > 2147483647)
			ft_error();
	}
	if (*s == '+' || *s == '-')
		ft_error();
	return (res * sign);
}

int	ft_count_words(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != '\0')
			i++;
		while (*s != ' ' && *s != '\0')
			s++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		i;
	int					j;

	i = 0;
	j = 0;
	new = malloc (len + 1);
	if (!new)
		return (NULL);
	while (i++ < start)
		j++;
	i = 0;
	while (s[start] && start < len + j)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *s)
{
	char	**new;
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	j = 0;
	new = malloc (ft_count_words(s) * sizeof(char *) + 1);
	if (!new)
		return (NULL);
	while (k < ft_count_words(s))
	{
		while (s[i] == ' ' && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
		new[k] = ft_substr(s, j, i - j);
		if (!new[k])
			free2d(new, k, 1);
		k++;
	}
	new[k] = NULL;
	return (new);
}

char	*ft_strjoin(char *s, char *buffer)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_strdup(buffer));
	string = malloc(ft_strlen(s) + ft_strlen(buffer) + 1);
	if (!string)
		return (free(s), s = NULL);
	while (s[i])
	{
		string[i] = s[i];
		i++;
	}
	while (buffer[j])
	{
		string[i] = buffer[j];
		i++;
		j++;
	}
	string[i] = '\0';
	free(s);
	return (string);
}


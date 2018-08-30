/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:20:24 by kpeng             #+#    #+#             */
/*   Updated: 2018/08/28 15:07:53 by kpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

int		is_separator(char c)
{
	if (c == ' '
	|| c == '\t'
	|| c == '\n')
		return (1);
	return (0);
}

int		ft_count_word(char *str)
{
	unsigned int wc;
	unsigned int index;
	short state;

	index = 0;
	wc = 0;
	state = 0;
	while (str[index])
	{
		if (is_separator(str[index]))
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++wc;
		}
		++index;
	}
	return (wc);
}

int		ft_next_word_len(char *str, int index)
{
	int		wc;
	int 	i;

	wc = 0;
	i = index;
	while (str[i])
	{
		if (!is_separator(str[i]))
			wc++;
		else
			break;
		i++;
	};
	return (wc);
}

char	**ft_split_whitespaces(char *str)
{
	int 	index;
	int 	word;
	char 	**arr;
	int 	i;
	int 	len;

	word = 0;
	index = 0;
	arr = malloc(sizeof(char *) * ft_count_word(str) + 1);
	while (str[index])
	{
		if (is_separator(str[index]))
		{
			index++;
			continue;
		}
		len = ft_next_word_len(str, index) + 1;
		arr[word] = malloc(sizeof(char *) * len);
		i = 0;
		while (i < len - 1)
		{
			arr[word][i] = str[index];
			i++;
			index++;
		}
		arr[word][i] = '\0';
		word++;
	}
	arr[word] = (char *)(0);
	return (arr);
}

void ft_print_words_tables(char **tab)
{
	int		index;
	int		jndex;
	
	index = 0;
	while (tab[index] != '\0')
	{
		jndex = 0;
		while (tab[index][jndex] != '\0')
		{
			ft_putchar(tab[index][jndex]);
			jndex++;
		}
		ft_putchar('\n');
		index++;
	}
}
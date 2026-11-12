/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulits_parsing_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labu-mus <labu-mus@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:43:07 by labu-mus          #+#    #+#             */
/*   Updated: 2026/11/10 18:43:09 by labu-mus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_world;

	i = 0;
	count = 0;
	in_world = 0;
	while (s[i])
	{
		if (s[i] != c && in_world == 0)
		{
			count++;
			in_world = 1;
		}
		else if (s[i] == c)
			in_world = 0;
		i++;
	}
	return (count);
}

static char	*copy_word(char const *s, int len)
{
	char	*word;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word [i] = '\0';
	return (word);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_word(char **words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[i] = copy_word(s, word_len(s, c));
			if (!split[i])
				return (free_word(split, i), NULL);
			i++;
			s += word_len(s, c);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

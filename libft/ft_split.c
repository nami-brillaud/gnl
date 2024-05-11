/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:31:53 by nfujisak          #+#    #+#             */
/*   Updated: 2024/04/29 16:32:57 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_previous(char **array, size_t i_word)
{
	while (i_word > 0)
	{
		free(array[i_word]);
		i_word--;
	}
	free(array);
}

static char	**splitter(char **array, char const *s, char c, size_t wordcount)
{
	size_t	i_word;
	size_t	j_indiv;

	i_word = 0;
	j_indiv = 0;
	while (i_word < wordcount)
	{
		while (s[j_indiv] && s[j_indiv] == c)
			j_indiv++;
		if (s[j_indiv] != '\0')
		{
			array[i_word] = ft_substr(s, j_indiv, word_length(&s[j_indiv], c));
			if (array[i_word] == NULL)
			{
				free_previous(array, i_word);
				return (NULL);
			}
			while (s[j_indiv] && s[j_indiv] != c)
				j_indiv++;
			i_word++;
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	wordcount;

	if (s == NULL)
		return (NULL);
	wordcount = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (array == NULL)
		return (NULL);
	array[wordcount] = NULL;
	splitter(array, s, c, wordcount);
	return (array);
}

// #include <stdio.h>
// int main(void)
// {
// 	char test[] = "bbCCDD";
// 	char c = 'b';
// 	char **result;
// 	size_t	i;

// 	i = 0;
// 	result = ft_split(test, c);
// 	while (i < 2)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }
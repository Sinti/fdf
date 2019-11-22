/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <elibrahimi.soufiane@gmail>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:22:24 by selibrah          #+#    #+#             */
/*   Updated: 2019/04/21 04:20:14 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int				i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	ret = ret + (unsigned char)str1[i] - (unsigned char)str2[i];
	while ((unsigned char)str2[i] != '\0' && ret == 0)
	{
		if ((unsigned char)str1[i] != '\0')
		{
			ret = ret + (unsigned char)str1[i] - (unsigned char)str2[i];
			i++;
		}
		else
			ret = ret + (unsigned char)str1[i] - (unsigned char)str2[i];
	}
	if ((unsigned char)str2[i] == '\0' && ret == 0)
		ret = ret + (unsigned char)str1[i] - (unsigned char)str2[i];
	return (ret);
}

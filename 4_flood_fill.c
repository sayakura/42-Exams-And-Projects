/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_flood_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:48:02 by kpeng             #+#    #+#             */
/*   Updated: 2018/10/01 18:06:38 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : flood_fill
Expected files   : *.c, *.h
Allowed functions: -
--------------------------------------------------------------------------------

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.

Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.

The flood_fill function won't fill diagonally.

The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);

The t_point structure is prototyped like this:

  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

Example:

$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}

$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0

1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$> 
*/
typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	t_point temp;
	
	if (tab[begin.x][begin.y] == '0')
		tab[begin.x][begin.y] = 'F';
	if (tab[begin.x][begin.y + 1] == '0')
	{
		temp.x = begin.x;
		temp.y = begin.y + 1;
		flood_fill(tab, size, temp);
	}
	if (tab[begin.x + 1][begin.y] == '0')
	{
		temp.x = begin.x + 1;
		temp.y = begin.y;
		flood_fill(tab, size, temp);
	}
	if (tab[begin.x - 1][begin.y] == '0')
	{
		temp.x = begin.x - 1;
		temp.y = begin.y;
		flood_fill(tab, size, temp);
	}
	if (tab[begin.x][begin.y - 1] == '0')
	{
		temp.x = begin.x;
		temp.y = begin.y - 1;
		flood_fill(tab, size, temp);
	}
}
/** test main **/
/*
#include <stdio.h>
#include <stdlib.h>
char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
			area[i][j] = zone[i][2 * j];
	}
	return (area);
}

int main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	t_point size  = {8, 5};
	t_point begin = {2, 2};
	char **area = make_area(zone, size.x, size.y);
	flood_fill(area, size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
		printf("\n");
	}
	free(area);
	return (0);
}
*/
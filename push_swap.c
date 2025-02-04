#include "swap.h"
void print_list(t_stack a) {
  t_node *current = a.top;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
void sort_ar(t_program *program)
{
	program->sorted_array=malloc(sizeof(int)* program->total_size);
	int i = 0;
		t_node *current = program->a->top;
	while (current)
	{
		program->sorted_array[i++] = current->value;
		current = current->next;
	}
	bubble_sort(program);
}
void assign_indexes(t_program *program)
{
	t_node *cur=program->a->top;

	while(cur)
	{
		int i=0;
		while(i<program->total_size)
		{
			if(cur->value==program->sorted_array[i])
			{
				break;
			}
			i++;
		}
		cur->index=i;
		cur=cur->next;

	}
}
void get_chunk_size(t_program * program)
{
	if(program->total_size<=20)
		program->chunk_size=5;
	else if(program->total_size<=100)
		program->chunk_size=20;
	else
		program->chunk_size=40;
	printf("chunk size %d  %d\n", program->chunk_size, program->total_size);
}
int get_position(int index, t_stack a)
{
	t_node *cur=a.top;
	int position=0;
	while(cur)
	{
		if(cur->index==index)
		{
			break;
		}
		position++;
		cur=cur->next;
	}
	return position;

}
int get_cost(int position, t_program program)
{
	int cost =0;
	if(position < program.a->size/2)
	{
		int i =position;
		while(i>0)
		{
			cost++;
			i--;
		}
	}
	else{
		int i=position;
		while(i<program.a->size+1)
		{
			cost++;
			i++;
		}
	}
	return cost;
}
int is_in_chunk(int index, int start, int chunk_size)
{
	if(index >= start && index <=(start+chunk_size))
		{
			//printf("index in chunk %d    start %d  finish %d\n", index, start, start+chunk_size);
			return 1;}
	else
		return 0;
}
// void sort_stack(t_program *program)
// {
// 	//int min_index=9999999999;
// 	t_node *cur;
// 	int i=0;
// 	while(program->a->size>0)
// {


// 	int k=program->chunk_size;

// 	while(k>0)
// 	{
// 		int min_index=999999999;
// 		int second=99999999;

// 		printf("SIZE a %d\n", program->a->size);
// 		cur=program->a->top;
// 		while(cur)
// 		{
// 			if(is_in_chunk(cur->index, i, program->chunk_size))
// 			{
// 				if(cur->index<min_index)
// 					min_index=cur->index;
// 			}
// 			cur=cur->next;
// 		}
// 	cur=program->a->top;
// 	while(cur)
// 	{
// 		if(is_in_chunk(cur->index, i, program->chunk_size))
// 		{
// 			if(cur->index<second && cur->index!= min_index)
// 				second=cur->index;
// 		}
// 		cur=cur->next;

// 	}
// 		int position_min_index= get_position(min_index, *program->a);
// 	int position_second=get_position(second, *program->a);
// 	int to_push;
// 	if(get_cost(position_min_index, *program)<get_cost(position_second, *program))
// 		to_push=min_index;
// 	else{
// 		to_push=second;
// 	}
// 	int j;
// 	if(get_position(to_push, *program->a)< program->a->size /2)
// 	{
// 		j=get_position(to_push, *program->a);
// 		while(j>0)
// 		{
// 			ra(program);
// 			j--;
// 		}
// 	}
// 	else{
// 		j=get_position(to_push, *program->a);
// 		while(j<program->a->size+1)
// 		{
// 			rra(program);
// 			j++;
// 		}
// 	}
// 		printf("MIN: %d\n", min_index);
// 		printf("second: %d\n", second);
// 		pb(program);
// 		k--;
// 	}
// 	// int position_min_index= get_position(min_index, *program->a);
// 	// int position_second=get_position(second, *program->a);
// 	// int to_push;
// 	// if(get_cost(position_min_index, *program)<get_cost(position_second, *program))
// 	// 	to_push=min_index;
// 	// else{
// 	// 	to_push=second;
// 	// }
// 	// int j;
// 	// if(get_position(to_push, *program->a)< program->a->size /2)
// 	// {
// 	// 	j=get_position(to_push, *program->a);
// 	// 	while(j>0)
// 	// 	{
// 	// 		ra(program);
// 	// 		j--;
// 	// 	}
// 	// }
// 	// else{
// 	// 	j=get_position(to_push, *program->a);
// 	// 	while(j<program->a->size+1)
// 	// 	{
// 	// 		rra(program);
// 	// 		j++;
// 	// 	}
// 	// }

// 	i=i+program->chunk_size;

// }
// }
void sort_stack(t_program *program)
{
    t_node *cur;
    int i = 0;

    while (program->a->size > 0)
    {
        int k = program->chunk_size;

        while (k > 0 && program->a->size > 0)  // Add size check here
        {
            int min_index = 999999999;
            int second = 99999999;
            int found_valid = 0;  // Flag to track if we found valid numbers

            cur = program->a->top;
            while (cur)
            {
                if (is_in_chunk(cur->index, i, program->chunk_size))
                {
                    if (cur->index < min_index)
                    {
                        min_index = cur->index;
                        found_valid = 1;
                    }
                }
                cur = cur->next;
            }

            if (!found_valid)
                break;  // No valid numbers in this chunk

            cur = program->a->top;
            while (cur)
            {
                if (is_in_chunk(cur->index, i, program->chunk_size))
                {
                    if (cur->index < second && cur->index != min_index)
                        second = cur->index;
                }
                cur = cur->next;
            }
            if (program->a->size == 0)
                break;

            int position_min_index = get_position(min_index, *program->a);
            int position_second = get_position(second, *program->a);
            int to_push;

            if (get_cost(position_min_index, *program) < get_cost(position_second, *program))
                to_push = min_index;
            else
                to_push = second;

            int j = get_position(to_push, *program->a);
            if (j < program->a->size / 2)
            {
                while (j > 0)
                {
                    ra(program);
                    j--;
                }
            }
            else
            {
                while (j < program->a->size)
                {
                    rra(program);
                    j++;
                }
            }
            pb(program);
            k--;
        }
        i = i + program->chunk_size;
    }
}
int main(int argc, char *argv[])
{
 t_program program;
 t_stack a;
 t_stack b;
 stack_init(&a);
 stack_init(&b);
 program_init(&program, &a, &b);
 program.total_size=argc-1;
 get_chunk_size(&program);
	long num;
	if(argc < 4)
	{
		printf("Error\n");
		return 1;
	}
	int i=argc-1;
	while(i>0)
	{
		num=ft_atoi(argv[i]);

			if(!push(&a, num))
			{printf("Push error\n");
				return 0;
			}
		i--;
	}

	print_list(a);
	sort_ar(&program);
	assign_indexes(&program);
	t_node *cur=a.top;

	sort_stack(&program);
	printf("stack is sorted\n");
	printf("STACK B \n");
	print_list(b);
	if(if_sorted(&a)&& b.size==0)
		{printf("OK\n");
		printf("List A\n");
		print_list(a);
		print_list(b);
		}
	else
		{printf("KO\n");
		printf("Size B %d\n", b.size);
		}
//  int j=0;
//  while(j<program.total_size)
//  {
// 	printf("%d  ", program.sorted_array[j]);
// 	j++;
//  }
printf("\n");
printf("\nIndexes\n");
printf("A size: %d\n", a.size);

	return 0;
}

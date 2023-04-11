#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *me_ident);
void print_magic(unsigned char *me_ident);
void print_class(unsigned char *me_ident);
void print_data(unsigned char *me_ident);
void print_version(unsigned char *me_ident);
void print_abi(unsigned char *me_ident);
void print_osabi(unsigned char *me_ident);
void print_type(unsigned int me_type, unsigned char *me_ident);
void print_entry(unsigned long int me_entry, unsigned char *me_ident);
void close_elf(int elf);

/**
 * check_elf - Entry point to Check an ELF file.
 * Project BY OLAOLUWA EMMANUEL IDOWU
 * @me_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *me_ident)
{
	int my_index;

	for (my_index = 0; my_index < 4; my_index++)
	{
		if (me_ident[my_index] != 127 &&
		    me_ident[my_index] != 'E' &&
		    me_ident[my_index] != 'L' &&
		    me_ident[my_index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Entry point to Print the magic numbers of an ELF header.
 * @me_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *me_ident)
{
	int my_index;

	printf("  Magic:   ");

	for (my_index = 0; my_index < EI_NIDENT; my_index++)
	{
		printf("%02x", me_ident[my_index]);

		if (my_index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Entry point to prints the class of an ELF header.
 * @me_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *me_ident)
{
	printf("  Class:                             ");

	switch (me_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", me_ident[EI_CLASS]);
	}
}

/**
 * print_data - Entry point to Prints the data of an ELF header.
 * @me_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *me_ident)
{
	printf("  Data:                              ");

	switch (me_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", me_ident[EI_CLASS]);
	}
}

/**
 * print_version - Entry point to print the version of an ELF header.
 * @me_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *me_ident)
{
	printf("  Version:                           %d",
	       me_ident[EI_VERSION]);

	switch (me_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Entry point to print the OS/ABI of an ELF header.
 * @me_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *me_ident)
{
	printf("  OS/ABI:                            ");

	switch (me_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", me_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Entry point to print the ABI version of an ELF header.
 * @me_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *me_ident)
{
	printf("  ABI Version:                       %d\n",
	       me_ident[EI_ABIVERSION]);
}

/**
 * print_type - Entry point to prints the type of an ELF header.
 * @me_type: The ELF type.
 * @me_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int me_type, unsigned char *me_ident)
{
	if (me_ident[EI_DATA] == ELFDATA2MSB)
		me_type >>= 8;

	printf("  Type:                              ");

	switch (me_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", me_type);
	}
}

/**
 * print_entry - Entry point to print the entry point of an ELF header.
 * @me_entry: The address of the ELF entry point.
 * @me_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int me_entry, unsigned char *me_ident)
{
	printf("  Entry point address:               ");

	if (me_ident[EI_DATA] == ELFDATA2MSB)
	{
		me_entry = ((me_entry << 8) & 0xFF00FF00) |
			  ((me_entry >> 8) & 0xFF00FF);
		me_entry = (me_entry << 16) | (me_entry >> 16);
	}

	if (me_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)me_entry);

	else
		printf("%#lx\n", me_entry);
}

/**
 * close_elf - Entry point to close an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Entry point to display the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int openMe, readMe;

	openMe = open(argv[1], O_RDONLY);
	if (openMe == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	readMe = read(o, header, sizeof(Elf64_Ehdr));
	if (readMe == -1)
	{
		free(header);
		close_elf(openMe);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->me_ident);
	printf("ELF Header:\n");
	print_magic(header->me_ident);
	print_class(header->me_ident);
	print_data(header->me_ident);
	print_version(header->me_ident);
	print_osabi(header->me_ident);
	print_abi(header->me_ident);
	print_type(header->me_type, header->me_ident);
	print_entry(header->me_entry, header->me_ident);

	free(header);
	close_elf(openMe);
	return (0);

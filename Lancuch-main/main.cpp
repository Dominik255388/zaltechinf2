#include <stdio.h>

void male_litery(char *ciag);
void wielkie_litery(char *ciag);
int dlugosc_tekstu(char *ciag);
void combineStrings(char *source1, char *source2, char *destination);

int main(int argc, char const *argv[]) {

    char tekst[] = "A5dhnJ<> ?!acdRT";
    char source1[] = "Ala";
    char source2[] = " ma kota";
    char source3[80] = "";

    puts("\nPolaczony tekst:");
    combineStrings(source1, source2, source3);
    printf("%s\n", source3);

    puts("\nTekst:");
    printf("%s", tekst);

    puts("\n\nMale litery:");
    male_litery(tekst);
    printf("%s", tekst);

    puts("\n\nDuze litery:");
    wielkie_litery(tekst);
    printf("%s", tekst);

    printf("\n\nTekst ma dlugosc: %d\n", dlugosc_tekstu(tekst));
    return 0;
}

void male_litery(char *ciag)
{
    while (*ciag)
    {
        if ('A' <= *ciag && *ciag <= 'Z')
        {
            *ciag += ('a' - 'A');
        }
        ciag++;
    }
}

void wielkie_litery(char *ciag)
{
    while (*ciag)
    {
        if ('a' <= *ciag && *ciag <= 'z')
        {
            *ciag -= ('a' - 'A');
        }
        ciag++;
    }
}

int dlugosc_tekstu(char *ciag)
{
    int i = 0;

    while (*ciag)
    {
        i++;
        ciag++;
    }
    return i;
}

void combineStrings(char *source1, char *source2, char *destination)
{
    while (*source1)
    {
        *destination = *source1;
        destination++;
        source1++;
    }

    while (*source2)
    {
        *destination = *source2;
        destination++;
        source2++;
    }

}

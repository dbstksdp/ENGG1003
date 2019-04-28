/* This is going to be the thing that runs all of your different functions */

#include <stdio.h>


//Rotation Cipher
const char theAlphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char* theEncryptedMessage1 = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.\0";
char* theMessage1 = "I love basketball. My favourite player is Kobe Bryant\0";


//Substitution Cipher
const char theKey[] = {'K', 'E', 'I', 'J', 'U', 'T', 'V', 'H', 'P', 'S', 'N', 'C', 'F', 'A', 'M', 'W', 'G', 'D', 'Q', 'X', 'Z', 'Y', 'B', 'R', 'O', 'L'};
char* theEncryptedMessage2 = "RCR VYE BGBX HBNX FHB FXNQBRV YM RNXFH IZNQEBCJ FHB PCJB? C FHYEQHF KYF. CF'J KYF N JFYXV FHB DBRC PYEZR FBZZ VYE. CF'J N JCFH ZBQBKR. RNXFH IZNQEBCJ PNJ N RNXA ZYXR YM FHB JCFH, JY IYPBXMEZ NKR JY PCJB HB LYEZR EJB FHB MYXLB FY CKMZEBKLB FHB OCRCLHZYXCNKJ FY LXBNFB ZCMB… HB HNR JELH N AKYPZBRQB YM FHB RNXA JCRB FHNF HB LYEZR BGBK ABBI FHB YKBJ HB LNXBR NWYEF MXYO RVCKQ. FHB RNXA JCRB YM FHB MYXLB CJ N INFHPNV FY ONKV NWCZCFCBJ JYOB LYKJCRBX FY WB EKKNFEXNZ. HB WBLNOB JY IYPBXMEZ… FHB YKZV FHCKQ HB PNJ NMXNCR YM PNJ ZYJCKQ HCJ IYPBX, PHCLH BGBKFENZZV, YM LYEXJB, HB RCR. EKMYXFEKNFBZV, HB FNEQHF HCJ NIIXBKFCLB BGBXVFHCKQ HB AKBP, FHBK HCJ NIIXBKFCLB ACZZBR HCO CK HCJ JZBBI. CXYKCL. HB LYEZR JNGB YFHBXJ MXYO RBNFH, WEF KYF HCOJBZM.\0";
char* theMessage2 = "DID YOU EVER HEAR THE TRAGEDY OF DARTH PLAGUEIS THE WISE? I THOUGHT NOT. IT'S NOT A STORY THE JEDI WOULD TELL YOU. IT'S A SITH LEGEND. DARTH PLAGUEIS WAS A DARK LORD OF THE SITH, SO POWERFUL AND SO WISE HE COULD USE THE FORCE TO INFLUENCE THE MIDICHLORIANS TO CREATE LIFE… HE HAD SUCH A KNOWLEDGE OF THE DARK SIDE THAT HE COULD EVEN KEEP THE ONES HE CARED ABOUT FROM DYING. THE DARK SIDE OF THE FORCE IS A PATHWAY TO MANY ABILITIES SOME CONSIDER TO BE UNNATURAL. HE BECAME SO POWERFUL… THE ONLY THING HE WAS AFRAID OF WAS LOSING HIS POWER, WHICH EVENTUALLY, OF COURSE, HE DID. UNFORTUNATELY, HE TAUGHT HIS APPRENTICE EVERYTHING HE KNEW, THEN HIS APPRENTICE KILLED HIM IN HIS SLEEP. IRONIC. HE COULD SAVE OTHERS FROM DEATH, BUT NOT HIMSELF.\0";
char* theEncryptedMessage3 = "OCLHNBZ DYXRNK CJ FHB WBJF WNJABFWNZZ IZNVBX BGBX. C FXEZV XBJIBLF HCO.\0";
char* theMessage3 = "Michael Jordan is the best basketball player ever. I truly respect him.\0";


/*** These are the function headers ***/

/* FUNCTION 1 */
void encryptRotation(char* theMessage, int key, char* theOutput);

/* FUNCTION 2 */
void decryptRotation(char* theEncryptedMessage, int key, char* theOutput);

/* FUNCTION 3 */
void encryptSubstitution(char* theMessage, char* theOutput);

/* FUNCTION 4 */
void decryptSubstitution(char* theEncryptedMessage, char* theOutput);



int main() {

    char theOutput[511];                                            //Since there are 511 characters as the length of 'theEncryptedMessage' string. Less than 511 will cut off the string, and more will not allow it to print correctly.

    //F1
    encryptRotation(theMessage1, 7, theOutput);
    printf("Rotation Cipher Encryption:%s \n\n",theOutput);

    //F2
    decryptRotation(theEncryptedMessage1, 7, theOutput);
    printf("Rotation Cipher Decryption: %s \n\n",theOutput);

    //F3
    encryptSubstitution(theMessage3, theOutput);
    printf("Substitution Cipher Encryption: %s \n\n",theOutput);

    //F4
    decryptSubstitution(theEncryptedMessage2, theOutput);
    printf("Substitution Cipher Decryption: %s \n\n",theOutput);

    return 0;
}




/*** Function Bodies ***/

/* Returns the position of a character in the alphabet array. */
int getIndex(char theChar){
    //Loop through the alphabet until the characters match then return the position of the character.
    int i = 0;
    while(theChar != theAlphabet[i]){
        i++;
    }

    return i;
}

/* Returns the position of a character in the alphabet array. */
int getIndexKey(char theChar){
    //Loop through the alphabet until the characters match then return the position of the character.
    int i = 0;
    while(theChar != theKey[i]){
        i++;
    }

    return i;
}

/*
    Scan over theMessage (unencrypted) apply the shift amount
    to each character, store the result in an array.
*/
void encryptRotation(char* theMessage, int key, char* theOutput){

    // const double sizeOfInput = sizeof(theMessage);             //This gets the size in bytes.
    // const double numberElements = sizeOfInput/sizeof(char);    //Gets number of elements by dividing by data type size.

    int shiftAmount = key%26;            //This is the rotation amount.

    /*
        A  loop that moves through input message and applies rotation to
        each character storing result in output string.
    */
    char currentChar = ' ';
    int i = 0;                          //This counter specifies which character of message loop is up to.
    int alphabetIndex = 0;
    while(currentChar != '\0')          //Loop continues until NULL character is found.
    {
        currentChar = (theMessage)[i];
        if(currentChar >= 97 && currentChar <=122)    //If true the character is not uppercase, convert to uppercase.
        {
            if(currentChar > 115){                                  //Using an IF statement to check whether it is TUVWXYZ which will need to overflow to the beginning of the array.
                currentChar -= 19;                                  //Minusing 19 positions in the array to account for the shift of 7.
                currentChar -= 32;                                  //Make the letter A uppercase.
                alphabetIndex = getIndex(currentChar);              //Assign the index.

                theOutput[i] = theAlphabet[alphabetIndex];          //Store the rotated character in the output.
                i++;
            }
            else{
            currentChar -= 32;                                      //Make the letter A uppercase.

            alphabetIndex = getIndex(currentChar);                //Get position of character in alphabet.
            alphabetIndex += shiftAmount;                         //Get position of character after rotation.
            theOutput[i] = theAlphabet[alphabetIndex];            //Store the rotated character in the output.-
            i++;
            }

        }
        else if(currentChar >= 65 && currentChar <=90 ){
            if(currentChar > 83){
                currentChar -= 19;
                alphabetIndex = getIndex(currentChar);
                theOutput[i] = theAlphabet[alphabetIndex];            //Store the rotated character in the output.-
                i++;
            }
            else{
            alphabetIndex = getIndex(currentChar);                //Get position of character in alphabet.
            alphabetIndex += shiftAmount;                         //Get position of character after rotation.
            theOutput[i] = theAlphabet[alphabetIndex];            //Store the rotated character in the output.-

            i++;
            }
        }else{                                                      //The case when the character is not a letter.

            theOutput[i] = currentChar;                           //It's not a letter so copy it to output but don't rotate it.
            i++;
        }
    }
}

/* FUNCTION 2 */
void decryptRotation(char* theEncryptedMessage, int key, char* theOutput){



    // const double sizeOfInput = sizeof(theMessage);             //This gets the size in bytes.
    // const double numberElements = sizeOfInput/sizeof(char);    //Gets number of elements by dividing by data type size.

    int shiftAmount = key%26;            //This is the rotation amount.

    /*
        A  loop that moves through input message and applies rotation to
        each character storing result in output string.
    */
    char currentChar = ' ';
    int i = 0;                          //This counter specifies which character of message loop is up to.
    int alphabetIndex = 0;
    while(currentChar != '\0')          //Loop continues until NULL character is found.
    {
        currentChar = (theEncryptedMessage)[i];

        if(currentChar >= 65 && currentChar <=90 ){
           if(currentChar < 72){                                    //Rotating backwards, opposite way to before, checking that if it is less than 7 positions in the array.
                currentChar += 19;                                  //Therefore, adding 19 to get the right rotational point.
                alphabetIndex = getIndex(currentChar);              //Assign the index.
                theOutput[i] = theAlphabet[alphabetIndex];          //Store the rotated character
                i++;
            }
            else{
            alphabetIndex = getIndex(currentChar);                  //Get position of character in alphabet.
            alphabetIndex -= shiftAmount;                          //Get position of character after rotation.
            theOutput[i] = theAlphabet[alphabetIndex];             //Store the rotated character in the output.-

            i++;
            }
        }
        else{                                                      //The case when the character is not a letter.

            theOutput[i] = currentChar;                           //It's not a letter so copy it to output but don't rotate it.
            i++;
        }
    }
}

/* FUNCTION 3 */
void encryptSubstitution(char* theMessage, char* theOutput){


    /*
        A  loop that moves through input message and applies rotation to
        each character storing result in output string.
    */
    char currentChar = ' ';
    int i = 0;                          //This counter specifies which character of message loop is up to.
    int keyIndex= 0;

    //Read through encrypted message.
    while(currentChar != '\0')          //Loop continues until NULL character is found.
    {
        currentChar = (theMessage)[i];

        if(currentChar >= 65 && currentChar <=90 ){					//If uppercase letter.

            keyIndex = getIndexKey(currentChar);              // Get index of character from alphabet.
            theOutput[i] = theAlphabet[keyIndex];          		// Get the Key character at that index.
            i++;


        }
        else if(currentChar>=97 && currentChar<= 122){			//The case when the character is not a letter.
            currentChar -= 32;									//This makes it uppercase.
            keyIndex = getIndexKey(currentChar);              // Get index of character from alphabet.
            theOutput[i] = theAlphabet[keyIndex];          		// Get the Key character at that index.
            i++;
        }
        else{													//It's not a letter. It's like a space or a punctuation or something.
            theOutput[i] = currentChar;
            i++;
        }
    }
}

/* FUNCTION 4 */
void decryptSubstitution(char* theEncryptedMessage, char* theOutput ){


    /*
        A  loop that moves through input message and applies rotation to
        each character storing result in output string.
    */
    char currentChar = ' ';
    int i = 0;                          //This counter specifies which character of message loop is up to.
    int alphabetIndex = 0;

	//Read through encrypted message.
    while(currentChar != '\0')          //Loop continues until NULL character is found.
    {
        currentChar = (theEncryptedMessage)[i];

        if(currentChar >= 65 && currentChar <=90 ){					//If uppercase letter.

			alphabetIndex = getIndex(currentChar);              // Get index of character from alphabet.
			theOutput[i] = theKey[alphabetIndex];          		// Get the Key character at that index.
			i++;


        }
        else if(currentChar>=97 && currentChar<= 122){			//The case when the character is not a letter.
			currentChar -= 32;									//This makes it uppercase.
            alphabetIndex = getIndex(currentChar);              // Get index of character from alphabet.
			theOutput[i] = theKey[alphabetIndex];          		// Get the Key character at that index.
			i++;
        }
		else{													//It's not a letter. It's like a space or a punctuation or something.
			theOutput[i] = currentChar;
			i++;
		}
    }
}


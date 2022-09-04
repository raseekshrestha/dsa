import random #module to perform random operations
import string #for ascii characters/letters

#gets all uppercase letters from A-Z => "ABC.....XYZ"
letters = string.ascii_uppercase

letters = list(string.ascii_uppercase) #converts into a list => ["A","B"...."Y","Z"]

random.shuffle(letters) #randomly shuffles the letters in list

names = ["Rashik Shrestha","Reebhu Adhikari","Usha Suwal","Alok Khadka","Amshu Man Maharjan","Binisha Naga","Shisant ","Rachana Shrestha","Sayal Karki","Sailesh Achhami","Sarad Kathayat","Samyog Dhital","Manish Karki","Prashant Bista","Praveen Shrestha","Milan Gyawali","Amish Chaudhary","Aabhash Basnet","Nayan Shrestha","Kamal Soud","Nulok Rai","Perisa Koirala","Shriya Shrestha","Ivaan Prajapati","Lasta Pudasaini","Smarika Shrestha","Nirdesika Chuhan","Suzana Pyakhurel","Shirish Shrestha","Pranjal Neupane","Salil Shrestha","Suchak Niraula","Sulav Karki","Rohan Taujale","Saransh Sharma","Saurav Kathayat","Aastha Shrestha","Anmol Shrestha","Sisam Ghaju","Rachana Ghaju","Reya Awal","Krima Madhi","Sareena Shrestha","Rubeen Shrestha","Rohan Karanjit","Chirag Ds","Deepika Sainju"]

names.sort() #sorts names in ascending order

counter = 1

for letter in letters:
    # makes new list from the names that starts with the given letter
    # 1. using list comprehenshin
    names_starting_with_current_letter = [name for name in names if name.startswith(letter) ]

    # 2. long method
    # names_starting_with_current_letter = [] #initialize new list
    # for name in names:
    #     if name.startswith(letter): #checks if the currentName starts with "letter"
    #         names_starting_with_current_letter.append(name)


    #prints each names in "names_starting_with_current_letter" only if the list is not empty
    if names_starting_with_current_letter:
        for name in names_starting_with_current_letter:
            print(f"{counter}. {name}")
            counter += 1


# OUTPUT
# 1. Nayan Shrestha
# 2. Nirdesika Chuhan
# 3. Nulok Rai
# 4. Binisha Naga
# 5. Sailesh Achhami
# 6. Salil Shrestha
# 7. Samyog Dhital
# 8. Sarad Kathayat
# 9. Saransh Sharma
# 10. Sareena Shrestha
# 11. Saurav Kathayat
# 12. Sayal Karki
# 13. Shirish Shrestha
# 14. Shisant
# 15. Shriya Shrestha
# 16. Sisam Ghaju
# 17. Smarika Shrestha
# 18. Suchak Niraula
# 19. Sulav Karki
# 20. Suzana Pyakhurel
# 21. Manish Karki
# 22. Milan Gyawali
# 23. Ivaan Prajapati
# 24. Usha Suwal
# 25. Deepika Sainju
# 26. Chirag Ds
# 27. Kamal Soud
# 28. Krima Madhi
# 29. Lasta Pudasaini
# 30. Perisa Koirala
# 31. Pranjal Neupane
# 32. Prashant Bista
# 33. Praveen Shrestha
# 34. Aabhash Basnet
# 35. Aastha Shrestha
# 36. Alok Khadka
# 37. Amish Chaudhary
# 38. Amshu Man Maharjan
# 39. Anmol Shrestha
# 40. Rachana Ghaju
# 41. Rachana Shrestha
# 42. Rashik Shrestha
# 43. Reebhu Adhikari
# 44. Reya Awal
# 45. Rohan Karanjit
# 46. Rohan Taujale
# 47. Rubeen Shrestha
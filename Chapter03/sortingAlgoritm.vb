private sub SelectSortButton_Click()

Dim input as String 
input = InputBox("For Number List, enter 1" & vbNewLine & 
    "For Random Number List, enter 2",
    "Select the list you want to sort", 
     vbOKCancel)

If input = "1" Then
    sort("C4:L4")
ElseIf input = "2" Then
    sort("C5:L5")
Else
    MsgBox("Enter correct option", "Enter 1 or 2", vbOK)
End If

end sub

function sort(selectedRange as String) As Variant

startingTime = Now

Dim numbers(10) As Integer
For Each cell In Me.Sheets(0).Range(selectedRange)
    'Null check
    If Not IsEmpty(cell) Then
        numbers[i] = cell.Value
    End If
Next

'Bubble sort 1
Dim isSwapped As Boolean
unsortedElementCount = numbers.length
Do While isSwapped = false
    isSwapped = false
    For i = 0 To arraySize - 1
        if (numbers[i] > numbers[i + 1])
        {
            val = numbers[i]
            numbers[i] = numbers[i + 1]
            numbers[i + 1] = val
            isSwapped = true;
        }
    Next i
    --unsortedElementCount;
Loop

'Bubble sort 2
For j = i to numbers.length
    key = numbers[i];
     'insert numbers[i] into sorted sequence A[1,2,3,..,i-1]
     j= i-1;
     while (j>0 and numbers[j]>key)
         numbers[j+1] = A[j]
         j= j-1
     numbers[j+1] = key 
Next i

Dim i As Integer
For Each cell In Me.Sheets(0).Range(selectedRange)
    cell.Value = numbers[i]
    i++
Next

dur = Now - startingTime

MsgBox("Time:", CStr(dur))

end function

private sub CreateRandomNumberList_Click()

Dim i As Integer
Dim generatedNumbers As Variant
generatedNumbers = generateRandomNumber()

For Each cell In Me.Sheets(0).Range("C4:L4")
    cell.Value = generatedNumbers[i]
    i++
Next

For Each cell In Me.Sheets(0).Range("C5:L5")
    cell.Value = generatedNumbers[i]
    i++
Next

end sub

Sub GenerateRandomNumber() As Variant

For i = 0 To 10
    Dim rand As Double
    rand = Rnd * 98 + 1
    rand = Round(rand)

    If IsInArray(rand, GenerateRandomNumber) Then
        i--
    Else
        GenerateRandomNumber[i] = rand
    End If
Next i    

End Sub

Function IsInArray(valueToBeFound As String, arr As Variant) As Boolean

    IsInArray = (UBound(Filter(arr, valueToBeFound)) > -1)

End Function




private sub LinearSearchButton_Click


Dim input as Integer 
input = InputBox("Enter a number in the Searched List",
    "Select target", 
     vbOKCancel)

If Not input < 0 And input > 9999 Then
    address = LinearSearch(input)
Else
    MsgBox("Out Of Range", "Enter a number in the Searched List that is between 0 and 9999", vbOK)
End If

Cell("D9").Value = address

end sub

Function LinearSearch(numberToSearch as Integer) As Integer

For Each cell in Range("A12:A10011")
    If numberToSearch = cell.Value Then
        LinearSearch = cell.Address
        Exit Function
    End If
Next

End Function
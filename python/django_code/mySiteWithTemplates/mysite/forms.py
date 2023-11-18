from django import forms


class MyForm(forms.Form):
    num1 = forms.IntegerField(label="val1", widget = forms.NumberInput(attrs={"class": "form-control"}))
    num2 = forms.IntegerField(label="val2", widget = forms.NumberInput(attrs={"class": "form-control"}))
    email = forms.EmailField(required=False, widget = forms.EmailInput(attrs={"class": "form-control", "placeholder": "example@example.com"}))
    file = forms.ImageField(widget = forms.FileInput(attrs={"class": "form-control"}))

# class MyFormFrommodel(forms.ModelForm):
#     class Meta:
#         model = MyModel
#         fields = ["num1", "num2", "email", "file"]
#         widgets = {
#             "num1": forms.NumberInput(attrs={"class": "form-control"}),
#             "num2": forms.NumberInput(attrs={"class": "form-control"}),
#             "email": forms.EmailInput(attrs={"class": "form-control", "placeholder": "example@example.com"}),
#             "file": forms.FileInput(attrs={"class": "form-control"}),
#         }

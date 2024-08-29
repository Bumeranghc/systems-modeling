object fMain: TfMain
  Left = 195
  Top = 109
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1052#1086#1076#1077#1083#1100' '#1101#1092#1092#1077#1082#1090#1080#1074#1085#1086#1089#1090#1080' '#1087#1088#1077#1076#1087#1088#1080#1103#1090#1080#1103
  ClientHeight = 485
  ClientWidth = 634
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  TextHeight = 13
  object lV: TLabel
    Left = 8
    Top = 16
    Width = 183
    Height = 13
    Caption = #1055#1083#1072#1085#1086#1074#1072#1103' '#1077#1078#1077#1076#1085#1077#1074#1085#1072#1103' '#1087#1088#1086#1080#1079#1074#1086#1076'-'#1090#1100':'
  end
  object lA: TLabel
    Left = 8
    Top = 40
    Width = 184
    Height = 13
    Caption = #1044#1080#1072#1087#1072#1079#1086#1085' '#1082#1086#1083#1077#1073#1072#1085#1080#1103' '#1087#1086#1090#1088#1077#1073#1085#1086#1089#1090#1077#1081':'
  end
  object lB: TLabel
    Left = 8
    Top = 64
    Width = 194
    Height = 13
    Caption = #1044#1080#1072#1087#1072#1079#1086#1085' '#1082#1086#1083#1077#1073#1072#1085#1080#1103' '#1101#1092#1092#1077#1082#1090#1080#1074#1085#1086#1089#1090#1080':'
  end
  object lZ: TLabel
    Left = 304
    Top = 16
    Width = 144
    Height = 13
    Caption = #1062#1077#1085#1072' '#1079#1072' '#1077#1076#1080#1085#1080#1094#1091' '#1087#1088#1086#1076#1091#1082#1094#1080#1080':'
  end
  object lPeriod: TLabel
    Left = 304
    Top = 40
    Width = 71
    Height = 13
    Caption = #1055#1077#1088#1080#1086#1076', '#1076#1085#1077#1081':'
  end
  object lHowmanymodels: TLabel
    Left = 304
    Top = 64
    Width = 112
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1088#1086#1093#1086#1076#1086#1074':'
  end
  object eV: TEdit
    Left = 216
    Top = 8
    Width = 81
    Height = 21
    TabOrder = 0
    Text = '10'
  end
  object eA: TEdit
    Left = 216
    Top = 32
    Width = 81
    Height = 21
    TabOrder = 1
    Text = '7'
  end
  object eB: TEdit
    Left = 216
    Top = 56
    Width = 81
    Height = 21
    TabOrder = 2
    Text = '2'
  end
  object eZ: TEdit
    Left = 464
    Top = 8
    Width = 73
    Height = 21
    TabOrder = 3
    Text = '1'
  end
  object ePeriod: TEdit
    Left = 464
    Top = 32
    Width = 73
    Height = 21
    TabOrder = 4
    Text = '240'
  end
  object bProcess: TButton
    Left = 8
    Top = 152
    Width = 617
    Height = 33
    Caption = #1055#1088#1086#1084#1086#1076#1077#1083#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 5
    OnClick = bProcessClick
  end
  object eHowmanymodels: TEdit
    Left = 464
    Top = 56
    Width = 73
    Height = 21
    ReadOnly = True
    TabOrder = 6
    Text = '3'
  end
  object pModel: TPanel
    Left = 8
    Top = 192
    Width = 617
    Height = 289
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1072#1088#1072#1084#1077#1090#1088#1099' '#1080' '#1087#1088#1086#1084#1086#1076#1077#1083#1080#1088#1091#1081#1090#1077' '#1087#1086#1074#1077#1076#1077#1085#1080#1077' '#1089#1080#1089#1090#1077#1084#1099
    TabOrder = 7
    object lAverage: TLabel
      Left = 1
      Top = 275
      Width = 615
      Height = 13
      Align = alBottom
      ExplicitWidth = 3
    end
  end
  object cbDay: TCheckBox
    Left = 8
    Top = 88
    Width = 289
    Height = 17
    Caption = #1055#1077#1088#1077#1087#1083#1072#1085#1080#1088#1086#1074#1072#1090#1100' '#1077#1078#1077#1076#1085#1077#1074#1085#1091#1102' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
    TabOrder = 8
  end
  object cbMonth: TCheckBox
    Left = 8
    Top = 104
    Width = 289
    Height = 17
    Caption = #1055#1077#1088#1077#1087#1083#1072#1085#1080#1088#1086#1074#1072#1090#1100' '#1084#1077#1089#1103#1095#1085#1091#1102' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
    TabOrder = 9
  end
  object cbYear: TCheckBox
    Left = 8
    Top = 120
    Width = 273
    Height = 17
    Caption = #1055#1077#1088#1077#1087#1083#1072#1085#1080#1088#1086#1074#1072#1090#1100' '#1075#1086#1076#1086#1074#1091#1102' '#1087#1088#1086#1080#1079#1074#1086#1076#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
    TabOrder = 10
  end
  object udHowmanymodels: TUpDown
    Left = 537
    Top = 56
    Width = 16
    Height = 21
    Associate = eHowmanymodels
    Min = 1
    Max = 20
    Position = 3
    TabOrder = 11
  end
end
